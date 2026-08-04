import express from "express";
import {
  createSpecialty, getSpecialties, updateSpecialty, deleteSpecialty,
} from "../controllers/specialtyController.js";
import { authMiddleware } from "../middlewares/authMiddleware.js";
import { isAdmin } from "../middlewares/adminMiddleware.js";

const router = express.Router();

router.get("/", getSpecialties);
router.post("/", authMiddleware, isAdmin, createSpecialty);
router.put("/:id", authMiddleware, isAdmin, updateSpecialty);
router.delete("/:id", authMiddleware, isAdmin, deleteSpecialty);

export default router;