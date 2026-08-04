import express from "express";
import {
  saveListing, getMySavedListings, unsaveListing,
} from "../controllers/savedListingController.js";
import { authMiddleware } from "../middlewares/authMiddleware.js";

const router = express.Router();

router.get("/", authMiddleware, getMySavedListings);
router.post("/", authMiddleware, saveListing);
router.delete("/:id", authMiddleware, unsaveListing);

export default router;