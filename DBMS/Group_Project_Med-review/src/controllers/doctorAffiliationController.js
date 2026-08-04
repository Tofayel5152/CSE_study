import { prisma } from "../database/db.js";

export const addAffiliation = async (req, res, next) => {
  try {
    const { doctorId, hospitalId, isPrimary } = req.body;
    const affiliation = await prisma.doctorAffiliation.create({
      data: { doctorId, hospitalId, isPrimary },
    });
    res.status(201).json(affiliation);
  } catch (err) {
    next(err);
  }
};

export const removeAffiliation = async (req, res, next) => {
  try {
    await prisma.doctorAffiliation.delete({
      where: { doctorAffiliationId: req.params.id },
    });
    res.status(204).send();
  } catch (err) {
    next(err);
  }
};