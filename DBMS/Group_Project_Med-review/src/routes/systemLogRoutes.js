import express from "express";
import { getLogs, getLogById, deleteLog } from "../controllers/systemLogController.js";
import { authMiddleware } from "../middlewares/authMiddleware.js";
import { isAdmin } from "../middlewares/adminMiddleware.js";

const router = express.Router();

// All log routes are admin-only
router.get("/", authMiddleware, isAdmin, getLogs);
router.get("/:id", authMiddleware, isAdmin, getLogById);
router.delete("/:id", authMiddleware, isAdmin, deleteLog);

export default router;