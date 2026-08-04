import { prisma } from "../database/db.js";

export const createSpecialty = async (req, res, next) => {
  try {
    const { name, slug } = req.body;
    const specialty = await prisma.specialty.create({ data: { name, slug } });
    res.status(201).json(specialty);
  } catch (err) {
    next(err);
  }
};

export const getSpecialties = async (req, res, next) => {
  try {
    const specialties = await prisma.specialty.findMany();
    res.json(specialties);
  } catch (err) {
    next(err);
  }
};

export const updateSpecialty = async (req, res, next) => {
  try {
    const specialty = await prisma.specialty.update({
      where: { specialtyId: req.params.id },
      data: req.body,
    });
    res.json(specialty);
  } catch (err) {
    next(err);
  }
};

export const deleteSpecialty = async (req, res, next) => {
  try {
    await prisma.specialty.delete({ where: { specialtyId: req.params.id } });
    res.status(204).send();
  } catch (err) {
    next(err);
  }
};