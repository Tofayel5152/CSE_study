# Med Review API

A REST API for a hospital and doctor review platform. Users can browse hospitals, doctors, and medical services, submit ratings and reviews (with optional proof), vote on and report reviews, and save listings for later. Admins moderate reviews and manage core data.

Built with **Node.js**, **Express**, **Prisma**, and **PostgreSQL**.

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
├── controllers/
│   ├── authController.js
│   ├── hospitalController.js
│   ├── doctorController.js
│   ├── doctorAffiliationController.js
│   ├── specialtyController.js
│   ├── medicalServiceController.js
│   ├── reviewController.js
│   ├── savedListingController.js
│   └── systemLogController.js
├── routes/
│   ├── authRoutes.js
│   ├── hospitalRoutes.js
│   ├── doctorRoutes.js
│   ├── specialtyRoutes.js
│   ├── medicalServiceRoutes.js
│   ├── reviewRoutes.js
│   ├── savedListingRoutes.js
│   └── systemLogRoutes.js
├── middlewares/
│   ├── authMiddleware.js       # JWT verification, attaches req.user
│   ├── adminMiddleware.js      # role === 'ADMIN' guard
│   ├── uploadMiddleware.js     # Multer + Cloudinary config for review proof photos
│   ├── validateMiddleware.js   # Zod request validation
│   └── errorMiddleware.js      # centralized error handling (incl. Prisma error codes)
├── validators/
│   ├── authValidators.js
│   ├── hospitalValidators.js
│   ├── doctorValidators.js
│   ├── specialtyValidators.js
│   ├── medicalServiceValidators.js
│   ├── reviewValidators.js
│   ├── savedListingValidators.js
│   └── commonValidators.js
├── config/
│   └── cloudinary.js
├── database/
│   └── db.js                   # Prisma client + connect/disconnect helpers
├── prisma/
│   └── schema.prisma
├── seed.js                     # sample data for local/dev testing
└── server.js
```

---

## Setup

### 1. Clone and install

```bash
git clone <your-repo-url>
cd med-review
npm install
```

### 2. Environment variables

Create a `.env` file in the project root:

```env
# Database
DATABASE_URL=postgresql://user:password@host:5432/dbname

# Server
PORT=5000
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

```bash
npx prisma generate
npx prisma migrate deploy
```

### 4. (Optional) Seed sample data

Seeds 10 records per model — users (1 admin + 9 regular), specialties, hospitals, doctors, affiliations, services, reviews (mixed statuses), proofs, votes, reports, saved listings, and system logs. Useful for exercising every endpoint without manual setup.

```bash
node seed.js
```

All seeded users share the password `Password123!`. See the console output after seeding for the full list of test emails, including the admin account.

### 5. Run the server

```bash
npm start
```

Server runs at `http://localhost:5000` by default.

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

Base URL: `{{baseURL}}` (e.g. `http://localhost:5000/`)

### Auth (`/auth`)

| Method | Route | Access | Body |
|---|---|---|---|
| POST | `/auth/register` | Public | `firstName, lastName?, email, phone, nid, password` |
| POST | `/auth/login` | Public | `email, password` |
| POST | `/auth/logout` | Public | — |
| GET | `/auth/profile` | Logged in | — |

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

A Postman collection covering all endpoints (with sample request bodies, auth handling, and chained-ID test scripts) is recommended for manual/exploratory testing. Use the seeded admin account to test admin-gated routes, and a seeded regular user account to confirm those same routes correctly return `403`.

---

## License

Add your license here.
