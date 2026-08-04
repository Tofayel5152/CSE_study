# Med Review API

A REST API for a hospital and doctor review platform. Users can browse hospitals, doctors, and medical services, submit ratings and reviews (with optional proof), vote on and report reviews, and save listings for later. Admins moderate reviews and manage core data.

Built with **Node.js**, **Express**, **Prisma**, and **PostgreSQL** as a group project for the DBMS course (CSE 2423).

---

## Contents

- [Tech Stack](#tech-stack)
- [Project Structure](#project-structure)
- [Data Model](#data-model)
- [Setup](#setup)
- [Authentication](#authentication)
- [API Reference](#api-reference)
- [Validation](#validation)
- [Error Handling](#error-handling)
- [File Uploads](#file-uploads)
- [Deployment](#deployment)
- [Testing](#testing)
- [Documentation](#documentation)
- [License](#license)

---

## Tech Stack

- **Runtime:** Node.js (ESM modules)
- **Framework:** Express
- **ORM:** Prisma (`@prisma/client`, `@prisma/adapter-pg`)
- **Database:** PostgreSQL
- **Auth:** JWT (httpOnly cookie + Bearer token fallback)
- **Validation:** Zod
- **File uploads:** Multer + Cloudinary
- **Password hashing:** bcrypt

---

## Project Structure

```
.
├── prisma/
│   └── schema.prisma            # 12-model schema (see Data Model below)
├── prisma.config.ts              # Prisma 7 config (schema path, migrations path, datasource URL)
└── src/
    ├── config/
    │   └── cloudinary.js         # Cloudinary SDK config
    ├── controllers/
    │   ├── authController.js
    │   ├── userController.js
    │   ├── hospitalController.js
    │   ├── doctorController.js
    │   ├── doctorAffiliationController.js
    │   ├── specialtyController.js
    │   ├── medicalServiceController.js
    │   ├── reviewController.js
    │   ├── savedListingController.js
    │   └── systemLogController.js
    ├── database/
    │   └── db.js                 # Prisma client, wired to Postgres via @prisma/adapter-pg
    ├── generated/
    │   └── prisma/                # Prisma Client output (generated, not hand-edited)
    ├── lib/
    │   └── prisma.ts
    ├── middlewares/
    │   ├── authMiddleware.js      # JWT verification, attaches req.user
    │   ├── adminMiddleware.js     # role === 'ADMIN' guard
    │   ├── uploadMiddleware.js    # Multer + Cloudinary storage for review proof photos
    │   ├── validateRequest.js     # Zod request validation
    │   └── errorMiddleware.js     # 404 handler + centralized error handling (incl. Prisma error codes)
    ├── routes/
    │   ├── authRoutes.js
    │   ├── userRoutes.js
    │   ├── hospitalRoutes.js
    │   ├── doctorRoutes.js
    │   ├── specialtyRoutes.js
    │   ├── medicalServiceRoutes.js
    │   ├── reviewRoutes.js
    │   ├── savedListingRoutes.js
    │   └── systemLogRoutes.js
    ├── utils/
    │   └── generatetoken.js       # issues JWT, sets httpOnly cookie
    ├── validators/
    │   └── registrationValidator.js
    └── server.js                  # app entry point, route mounting, graceful shutdown
```

---

## Data Model

Defined in `prisma/schema.prisma` — 12 models on PostgreSQL, all primary keys as UUIDs:

| Model | Purpose |
|---|---|
| `User` | Account, credentials (hashed), role (`USER`/`ADMIN`) |
| `Hospital` | Hospital directory entries |
| `Doctor` | Doctor directory entries, linked to a `Specialty` |
| `DoctorAffiliation` | Many-to-many link between doctors and hospitals |
| `MedicalService` | Services offered by a hospital |
| `Specialty` | Medical specialties (used to categorize doctors) |
| `Review` | Rating + comment against a hospital, doctor, and/or service; moderation status |
| `ReviewProof` | Optional evidence attached to a review (bill, appointment number, or file) |
| `ReviewVote` | Helpful / not-helpful votes on a review, one per user |
| `ReviewReport` | User-submitted reports flagging a review for moderation |
| `SavedListing` | A user's bookmarked hospital, doctor, or service |
| `SystemLog` | Internal audit trail written by controllers via a `logAction()` helper |

Key enums: `UserRole`, `ApprovalStatus`, `ListingEntity`, `ProofType`, `LogSeverity`, `VoteType`, `ReportReason`, `DoctorType`.

---

## Setup

### 1. Clone and install

This project lives inside a larger coursework repository. Clone it and move into the project folder:

```bash
git clone https://github.com/Tofayel5152/CSE_study.git
cd CSE_study/DBMS/Group_Project_Med-review
npm install
```

### 2. Environment variables

Create a `.env` file in the project root:

```env
# Database
DATABASE_URL=postgresql://user:password@host:5432/dbname

# Server
PORT=3000
NODE_ENV=development

# JWT
JWT_SECRET=your_long_random_secret_here
JWT_EXPIRES_IN=7d

# Cloudinary (for review proof photo uploads)
CLOUDINARY_CLOUD_NAME=your_cloud_name
CLOUDINARY_API_KEY=your_api_key
CLOUDINARY_API_SECRET=your_api_secret

# CORS (frontend origin, required in production for cookies to work cross-site)
FRONTEND_URL=http://localhost:3000
```

### 3. Set up the database

The project uses Prisma's driver adapter (`@prisma/adapter-pg`) rather than a schema-level `url`, so the connection string is read from `DATABASE_URL` at runtime. No migrations are checked into the repo yet, so push the schema directly to your database:

```bash
npx prisma generate
npx prisma db push
```

`npm install` also triggers `prisma generate` automatically via the `postinstall` script.

### 4. (Optional) Seed sample data

```bash
npm run seed
```

This runs `prisma/seed.js`, intended to populate the database with sample users, hospitals, doctors, and reviews for exercising the API without manual setup. Add or update that file with your own fixture data as needed.

### 5. Run the server

```bash
npm start        # production
npm run dev       # development, with nodemon auto-reload
```

Server runs at `http://localhost:3000` by default (configurable via `PORT`).

---

## Authentication

- On **register** and **login**, a JWT is issued and set as an `httpOnly` cookie named `jwt`.
- Protected routes also accept a `Authorization: Bearer <token>` header as a fallback.
- `role` on the `User` model is either `USER` or `ADMIN`. Admin-only routes are gated by `adminMiddleware`.

| Route | Auth required |
|---|---|
| `POST /auth/register` | None |
| `POST /auth/login` | None |
| `POST /auth/logout` | None |
| `GET /auth/profile` | Logged in |

---

## API Reference

Base URL: `{{baseURL}}` (e.g. `http://localhost:3000/`)

### Auth (`/auth`)

| Method | Route | Access | Body |
|---|---|---|---|
| POST | `/auth/register` | Public | `firstName, lastName?, email, phone, nid, password` |
| POST | `/auth/login` | Public | `email, password` |
| POST | `/auth/logout` | Public | — |
| GET | `/auth/profile` | Logged in | — |

### Users (`/user`)

| Method | Route | Access | Body |
|---|---|---|---|
| GET | `/user` | Admin | — returns all users |
| GET | `/user/:id` | Logged in | — |
| PUT | `/user/:id` | Logged in | profile fields to update |
| DELETE | `/user/:id` | Logged in | — |

### Specialties (`/specialties`)

| Method | Route | Access | Body |
|---|---|---|---|
| GET | `/specialties` | Public | — |
| POST | `/specialties` | Admin | `name, slug` |
| PUT | `/specialties/:id` | Admin | `name?, slug?` |
| DELETE | `/specialties/:id` | Admin | — |

### Hospitals (`/hospitals`)

| Method | Route | Access | Body / Query |
|---|---|---|---|
| GET | `/hospitals` | Public | query: `city?, search?` |
| GET | `/hospitals/:id` | Public | — |
| POST | `/hospitals` | Admin | `name, address, city, country?` |
| PUT | `/hospitals/:id` | Admin | any of the above |
| DELETE | `/hospitals/:id` | Admin | — |

### Doctors (`/doctors`)

| Method | Route | Access | Body / Query |
|---|---|---|---|
| GET | `/doctors` | Public | query: `specialtyId?, search?` |
| GET | `/doctors/:id` | Public | — |
| POST | `/doctors` | Admin | `name, bmdcId, doctorType?, qualification, specialtyId` |
| PUT | `/doctors/:id` | Admin | any of the above |
| DELETE | `/doctors/:id` | Admin | — |
| POST | `/doctors/affiliations` | Admin | `doctorId, hospitalId, isPrimary?` |
| DELETE | `/doctors/affiliations/:id` | Admin | — |

### Medical Services (`/services`)

| Method | Route | Access | Body |
|---|---|---|---|
| GET | `/services/hospital/:hospitalId` | Public | — |
| POST | `/services` | Admin | `hospitalId, serviceName, description?` |
| PUT | `/services/:id` | Admin | `serviceName?, description?` |
| DELETE | `/services/:id` | Admin | — |

### Reviews (`/reviews`)

| Method | Route | Access | Body / Query |
|---|---|---|---|
| GET | `/reviews` | Public | query: `hospitalId?, doctorId?, serviceId?, status?` (defaults to `APPROVED`) |
| GET | `/reviews/MyReviews` | Logged in | returns the current user's own reviews, any status |
| GET | `/reviews/hospital/:name` | Public | partial, case-insensitive hospital name match |
| GET | `/reviews/doctor/:name` | Public | partial, case-insensitive doctor name match |
| GET | `/reviews/specialty/:name` | Public | partial, case-insensitive specialty name match |
| GET | `/reviews/:id` | Public | — |
| POST | `/reviews` | Logged in | `hospitalId?, doctorId?, serviceId?, staffRating, punctualityRating, knowledgeRating?, bedsideRating?, overallRating, comment` |
| PATCH | `/reviews/:id/status` | Admin | `status (PENDING/APPROVED/REJECTED), adminNotes?` |
| DELETE | `/reviews/:id` | Admin | — |
| POST | `/reviews/:id/proof` | Logged in | multipart form: `type (BILL/APPOINTMENT_NUMBER/FILE_UPLOAD)` + `proofValue` (text) or `proofImage` (file) |
| POST | `/reviews/:id/vote` | Logged in | `voteType (HELPFUL/NOT_HELPFUL)` — upserts, one vote per user per review |
| POST | `/reviews/:id/report` | Logged in | `reason (SPAM/OFFENSIVE_LANGUAGE/HIPAA_VIOLATION/FALSE_INFORMATION/OTHER), details?` |

> **Note on route order:** literal routes (`/MyReviews`, `/hospital/:name`, etc.) are registered before `/:id` in `reviewRoutes.js`. This is required — Express matches top to bottom, and `/:id` would otherwise swallow any literal path segment.

### Saved Listings (`/saved-listings`)

| Method | Route | Access | Body |
|---|---|---|---|
| GET | `/saved-listings` | Logged in | returns only the current user's saved listings |
| POST | `/saved-listings` | Logged in | `entityId, entityType (HOSPITAL/DOCTOR/MEDICAL_SERVICE)` |
| DELETE | `/saved-listings/:id` | Logged in | — |

### System Logs (`/system-logs`)

Read-only via the API — entries are written internally by other controllers via a `logAction()` helper, not created directly by clients.

| Method | Route | Access | Query |
|---|---|---|---|
| GET | `/system-logs` | Admin | `severity?, userId?, action?` |
| GET | `/system-logs/:id` | Admin | — |
| DELETE | `/system-logs/:id` | Admin | — |

---

## Validation

Request bodies are validated with Zod before reaching controllers. Invalid requests return:

```json
{
  "message": "Validation failed",
  "errors": [
    { "field": "staffRating", "message": "Number must be less than or equal to 5" }
  ]
}
```

Key rules enforced:
- Ratings (`staffRating`, `punctualityRating`, etc.) must be integers 1–5; `overallRating` must be 0–5.
- `email` must be valid format; `password` minimum 8 characters.
- `phone` must be 11 digits; `nid` must be 10–17 digits.
- Enum fields (`voteType`, `reason`, `status`, `entityType`, `doctorType`, `type`) are restricted to their defined values.
- `:id` route params must be valid UUIDs.

---

## Error Handling

All errors are returned as JSON with a consistent shape:

```json
{ "message": "Human-readable error message" }
```

Common status codes:

| Code | Meaning |
|---|---|
| 400 | Validation failure or malformed request |
| 401 | Not authenticated / invalid or missing token |
| 403 | Authenticated but not authorized (e.g. non-admin hitting an admin route) |
| 404 | Resource not found |
| 409 | Unique constraint violation (e.g. duplicate email, duplicate vote) |
| 500 | Unexpected server error |

---

## File Uploads

Review proof photos are uploaded via `multipart/form-data` and stored on **Cloudinary** (not local disk — required for persistence on platforms like Render where the filesystem resets on redeploy). Max file size: 5MB. Allowed formats: jpeg, png, webp, heic.

---

## Deployment

Deployed on [Render](https://render.com) as a Node web service.

**Build command:**
```bash
npm install && npx prisma generate
```

**Start command:**
```bash
npm start
```

Required environment variables must be set in Render's dashboard (see [Environment variables](#2-environment-variables) above). In production, `NODE_ENV=production` enables `secure: true` and `sameSite: "none"` on the auth cookie, required for cross-origin cookie delivery over HTTPS.

---

## Testing

A Postman collection covering all endpoints (with sample request bodies, auth handling, and chained-ID test scripts) is recommended for manual/exploratory testing. Seed an admin account (`role: ADMIN` in the `User` table) to test admin-gated routes, and a regular user account to confirm those same routes correctly return `403`.

---

## Documentation

Supporting course deliverables are included under `Report and  Presentation/`:

- `Project  Proposal.pdf`
- `MedReview_Project_Report.pdf`
- `MedReview_Presentation.pdf`

---

## License

ISC — see `package.json`. Submitted as coursework for CSE 2423 (Database Management Systems), IIUC.