import "dotenv/config";
import express from 'express';
import cookieParser from "cookie-parser";
import cors from "cors";
import { connectDB, disconnectDB } from "./database/db.js";

import authRoutes from "./routes/authRoutes.js"
import userRoutes from "./routes/userRoutes.js";
import hospitalRoutes from "./routes/hospitalRoutes.js";
import doctorRoutes from "./routes/doctorRoutes.js";
import specialtyRoutes from "./routes/specialtyRoutes.js";
import medicalServiceRoutes from "./routes/medicalServiceRoutes.js";
import reviewRoutes from "./routes/reviewRoutes.js";
import savedListingRoutes from "./routes/savedListingRoutes.js";
import { notFound, errorHandler } from "./middlewares/errorMiddleware.js";
import systemLogRoutes from "./routes/systemLogRoutes.js";
connectDB();



const PORT = process.env.PORT || 3000;
const app = express();

//Body Parsing Middleware
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(cookieParser());



app.use(cors({
  origin: process.env.FRONTEND_URL, 
  credentials: true, 
}));


//API ROUTES
app.get('/', (req, res) => {
  res.send('Hello, World!');
});

app.use("/auth",authRoutes);
app.use("/user", userRoutes);
app.use("/system-logs", systemLogRoutes);

app.use("/hospitals", hospitalRoutes);
app.use("/doctors", doctorRoutes);
app.use("/specialties", specialtyRoutes);
app.use("/services", medicalServiceRoutes);
app.use("/reviews", reviewRoutes);
app.use("/saved-listings", savedListingRoutes);


app.use(notFound);
app.use(errorHandler);


const server = app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}...`);
});



// Graceful shutdown
process.on("SIGTERM", async () => {
  console.log("SIGTERM received, shutting down gracefully");
  server.close(async () => {
    await disconnectDB();
    process.exit(0);
  });
});

