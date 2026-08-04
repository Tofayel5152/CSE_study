import { prisma } from "../database/db.js";

export const saveListing = async (req, res, next) => {
  try {
    const { entityId, entityType } = req.body; // HOSPITAL | DOCTOR | MEDICAL_SERVICE
    const saved = await prisma.savedListing.create({
      data: { userId: req.user.userId, entityId, entityType },
    });
    res.status(201).json(saved);
  } catch (err) {
    next(err);
  }
};

export const getMySavedListings = async (req, res, next) => {
  try {
    const saved = await prisma.savedListing.findMany({
      where: { userId: req.user.userId },
    });
    res.json(saved);
  } catch (err) {
    next(err);
  }
};

export const unsaveListing = async (req, res, next) => {
  try {
    await prisma.savedListing.delete({ where: { savedId: req.params.id } });
    res.status(204).send();
  } catch (err) {
    next(err);
  }
};