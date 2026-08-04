import express from "express";
import {
  createService, getServicesByHospital, updateService, deleteService,
} from "../controllers/medicalServiceController.js";
import { authMiddleware } from "../middlewares/authMiddleware.js";
import { isAdmin } from "../middlewares/adminMiddleware.js";

const router = express.Router();

router.get("/hospital/:hospitalId", getServicesByHospital);
router.post("/", authMiddleware, isAdmin, createService);
router.put("/:id", authMiddleware, isAdmin, updateService);
router.delete("/:id", authMiddleware, isAdmin, deleteService);

export default router;