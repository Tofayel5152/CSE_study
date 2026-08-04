import { prisma } from "../database/db.js";

export const createHospital = async (req, res, next) => {
  try {
    const { name, address, city, country } = req.body;
    const hospital = await prisma.hospital.create({
      data: { name, address, city, country },
    });
    res.status(201).json(hospital);
  } catch (err) {
    next(err);
  }
};

export const getHospitals = async (req, res, next) => {
  try {
    const { city, search } = req.query;
    const hospitals = await prisma.hospital.findMany({
      where: {
        ...(city && { city }),
        ...(search && { name: { contains: search, mode: "insensitive" } }),
      },
    });
    res.json(hospitals);
  } catch (err) {
    next(err);
  }
};

export const getHospitalById = async (req, res, next) => {
  try {
    const hospital = await prisma.hospital.findUniqueOrThrow({
      where: { hospitalId: req.params.id },
      include: { doctorAffiliations: { include: { doctor: true } }, medicalServices: true },
    });
    res.json(hospital);
  } catch (err) {
    next(err);
  }
};

export const updateHospital = async (req, res, next) => {
  try {
    const hospital = await prisma.hospital.update({
      where: { hospitalId: req.params.id },
      data: req.body,
    });
    res.json(hospital);
  } catch (err) {
    next(err);
  }
};

export const deleteHospital = async (req, res, next) => {
  try {
    await prisma.hospital.delete({ where: { hospitalId: req.params.id } });
    res.status(204).send();
  } catch (err) {
    next(err);
  }
};