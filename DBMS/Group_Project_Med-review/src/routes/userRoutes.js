import express from "express";
import { authMiddleware } from "../middlewares/authMiddleware.js";
import { getAllUsers, getUserById, updateUser, deleteUser } from "../controllers/userController.js";
import { isAdmin } from "../middlewares/adminMiddleware.js";

const router = express.Router();

router.get("/", authMiddleware,isAdmin, getAllUsers);
router.get("/:id", authMiddleware, getUserById);
router.put("/:id", authMiddleware, updateUser);
router.delete("/:id", authMiddleware, deleteUser);

export default router;