import express from "express";
import {
  createReview, getReviews, getReviewById, updateReviewStatus, deleteReview,
  addReviewProof, voteReview, reportReview, getMyReviews,
  getReviewsByHospitalName, getReviewsByDoctorName, getReviewsBySpecialtyName,
} from "../controllers/reviewController.js";
import { authMiddleware } from "../middlewares/authMiddleware.js";
import { isAdmin } from "../middlewares/adminMiddleware.js";

const router = express.Router();

router.get("/MyReviews/", authMiddleware, getMyReviews);
router.get("/hospital/:name", getReviewsByHospitalName);
router.get("/doctor/:name", getReviewsByDoctorName);
router.get("/specialty/:name", getReviewsBySpecialtyName);
router.get("/", getReviews);


router.get("/:id", getReviewById);
router.post("/", authMiddleware, createReview);
router.patch("/:id/status", authMiddleware, isAdmin, updateReviewStatus);
router.delete("/:id", authMiddleware, isAdmin, deleteReview);

router.post("/:id/proof", authMiddleware, addReviewProof);
router.post("/:id/vote", authMiddleware, voteReview);
router.post("/:id/report", authMiddleware, reportReview);

export default router;
