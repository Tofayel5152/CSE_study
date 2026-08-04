import express from "express";
import {
  createDoctor, getDoctors, getDoctorById, updateDoctor, deleteDoctor,
} from "../controllers/doctorController.js";
import { addAffiliation, removeAffiliation } from "../controllers/doctorAffiliationController.js";
import { authMiddleware } from "../middlewares/authMiddleware.js";
import { isAdmin } from "../middlewares/adminMiddleware.js";

const router = express.Router();

router.get("/", getDoctors);
router.get("/:id", getDoctorById);
router.post("/", authMiddleware, isAdmin, createDoctor);
router.put("/:id", authMiddleware, isAdmin, updateDoctor);
router.delete("/:id", authMiddleware, isAdmin, deleteDoctor);

router.post("/affiliations", authMiddleware, isAdmin, addAffiliation);
router.delete("/affiliations/:id", authMiddleware, isAdmin, removeAffiliation);

export default router;