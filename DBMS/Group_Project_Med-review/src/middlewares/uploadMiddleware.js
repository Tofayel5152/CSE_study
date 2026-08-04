import multer from "multer";
import { CloudinaryStorage } from "multer-storage-cloudinary";
import cloudinary from "../config/cloudinary.js";

const storage = new CloudinaryStorage({
  cloudinary,
  params: {
    folder: "med-review/review-proofs",
    allowed_formats: ["jpg", "jpeg", "png", "webp", "heic"],
    transformation: [{ width: 1600, height: 1600, crop: "limit" }],
  },
});

export const uploadProofImage = multer({
  storage,
  limits: { fileSize: 5 * 1024 * 1024 }, // 5MB file size limit
}).single("proofImage");