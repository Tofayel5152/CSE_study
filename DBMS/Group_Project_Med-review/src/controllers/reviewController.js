import { prisma } from "../database/db.js";
import { logAction } from "./systemLogController.js";


export const createReview = async (req, res, next) => {
  try {
    const {
      hospitalId, doctorId, serviceId,
      staffRating, punctualityRating, knowledgeRating, bedsideRating,
      overallRating, comment,
    } = req.body;

    const review = await prisma.review.create({
      data: {
        userId: req.user.userId,
        hospitalId, doctorId, serviceId,
        staffRating, punctualityRating, knowledgeRating, bedsideRating,
        overallRating, comment,
      },
    });
    res.status(201).json(review);
  } catch (err) {
    next(err);
  }
};

export const getReviews = async (req, res, next) => {
  try {
    const { hospitalId, doctorId, serviceId, status } = req.query;
    const reviews = await prisma.review.findMany({
      where: {
        ...(hospitalId && { hospitalId }),
        ...(doctorId && { doctorId }),
        ...(serviceId && { serviceId }),
        status: status || "APPROVED", // only show approved by default
      },
      include: { user: { select: { firstName: true, lastName: true } } },
      orderBy: { createdAt: "desc" },
    });
    res.json(reviews);
  } catch (err) {
    next(err);
  }
};

export const getReviewById = async (req, res, next) => {
  try {
    const review = await prisma.review.findUniqueOrThrow({
      where: { reviewId: req.params.id },
      include: { reviewProofs: true, reviewVotes: true },
    });
    res.json(review);
  } catch (err) {
    next(err);
  }
};

export const getMyReviews = async (req, res, next) => {
  try {
    const reviews = await prisma.review.findMany({
      where: { userId: req.user.userId },
      include: {
        hospital: { select: { name: true, city: true } },
        doctor: { select: { name: true } },
        service: { select: { serviceName: true } },
        reviewProofs: true,
      },
      orderBy: { createdAt: "desc" },
    });
    res.json(reviews);
  } catch (err) {
    next(err);
  }
};

// Admin: approve/reject a review
export const updateReviewStatus = async (req, res, next) => {
  try {
    const { status, adminNotes } = req.body;
    const review = await prisma.review.update({
      where: { reviewId: req.params.id },
      data: { status, adminNotes },
    });

    await logAction({
      userId: req.user.userId,
      action: "UPDATE_REVIEW_STATUS",
      severity: "INFO",
      details: `Review ${req.params.id} set to ${status}`,
      ipAddress: req.ip,
    });

    res.json(review);
  } catch (err) {
    next(err);
  }
};

export const deleteReview = async (req, res, next) => {
  try {
    await prisma.review.delete({ where: { reviewId: req.params.id } });

    await logAction({
      userId: req.user.userId,
      action: "DELETE_REVIEW",
      severity: "WARNING",
      details: `Review ${req.params.id} deleted`,
      ipAddress: req.ip,
    });

    res.status(204).send();
  } catch (err) {
    next(err);
  } 
};

// Add proof to a review
export const addReviewProof = async (req, res, next) => {
  try {
    const { type } = req.body;

    let proofValue;
    if (req.file) {
      proofValue = req.file.path; 
    } else if (req.body.proofValue) {
      proofValue = req.body.proofValue;
    } else {
      return res.status(400).json({ message: "Provide either a proofImage file or a proofValue" });
    }

    const proof = await prisma.reviewProof.create({
      data: { reviewId: req.params.id, type, proofValue },
    });

    res.status(201).json(proof);
  } catch (err) {
    next(err);
  }
};

// Vote helpful / not helpful (upsert so a user can change their vote)
export const voteReview = async (req, res, next) => {
  try {
    const { voteType } = req.body; // HELPFUL | NOT_HELPFUL
    const vote = await prisma.reviewVote.upsert({
      where: { reviewId_userId: { reviewId: req.params.id, userId: req.user.userId } },
      update: { voteType },
      create: { reviewId: req.params.id, userId: req.user.userId, voteType },
    });
    res.status(201).json(vote);
  } catch (err) {
    next(err);
  }
};

// Report a review
export const reportReview = async (req, res, next) => {
  try {
    const { reason, details } = req.body;
    const report = await prisma.reviewReport.create({
      data: { reviewId: req.params.id, userId: req.user.userId, reason, details },
    });
    res.status(201).json(report);
  } catch (err) {
    next(err);
  }
};

export const getReviewsByHospitalName = async (req, res, next) => {
  try {
    const { name } = req.params;
    const reviews = await prisma.review.findMany({
      where: {
        status: "APPROVED", // only show approved reviews publicly
        hospital: {
          name: { contains: name, mode: "insensitive" },
        },
      },
      include: {
        hospital: { select: { name: true, city: true } },
        doctor: { select: { name: true } },
        service: { select: { serviceName: true } },
      },
      orderBy: { createdAt: "desc" },
    });
    res.json(reviews);
  } catch (err) {
    next(err);
  }
};

export const getReviewsByDoctorName = async (req, res, next) => {
  try {
    const { name } = req.params;
    const reviews = await prisma.review.findMany({
      where: {
        status: "APPROVED",
        doctor: {
          name: { contains: name, mode: "insensitive" },
        },
      },
      include: {
        hospital: { select: { name: true, city: true } },
        doctor: { select: { name: true } },
        service: { select: { serviceName: true } },
      },
      orderBy: { createdAt: "desc" },
    });
    res.json(reviews);
  } catch (err) {
    next(err);
  }
};

export const getReviewsBySpecialtyName = async (req, res, next) => {
  try {
    const { name } = req.params;
    const reviews = await prisma.review.findMany({
      where: {
        status: "APPROVED",
        doctor: {
          specialty: {
            name: { contains: name, mode: "insensitive" },
          },
        },
      },
      include: {
        hospital: { select: { name: true, city: true } },
        doctor: { select: { name: true, specialty: { select: { name: true } } } },
        service: { select: { serviceName: true } },
      },
      orderBy: { createdAt: "desc" },
    });
    res.json(reviews);
  } catch (err) {
    next(err);
  }
};