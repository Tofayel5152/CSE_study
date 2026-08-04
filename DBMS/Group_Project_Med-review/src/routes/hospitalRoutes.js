import express from "express";
import {
  createHospital, getHospitals, getHospitalById, updateHospital, deleteHospital,
} from "../controllers/hospitalController.js";
import { authMiddleware } from "../middlewares/authMiddleware.js";
import { isAdmin } from "../middlewares/adminMiddleware.js";

const router = express.Router();

router.get("/", getHospitals);
router.get("/:id", getHospitalById);
router.post("/", authMiddleware, isAdmin, createHospital);
router.put("/:id", authMiddleware, isAdmin, updateHospital);
router.delete("/:id", authMiddleware, isAdmin, deleteHospital);

export default router;