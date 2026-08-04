import { prisma } from "../database/db.js";

export const createDoctor = async (req, res, next) => {
  try {
    const { name, bmdcId, doctorType, qualification, specialtyId } = req.body;
    const doctor = await prisma.doctor.create({
      data: { name, bmdcId, doctorType, qualification, specialtyId },
    });
    res.status(201).json(doctor);
  } catch (err) {
    next(err);
  }
};

export const getDoctors = async (req, res, next) => {
  try {
    const { specialtyId, search } = req.query;
    const doctors = await prisma.doctor.findMany({
      where: {
        ...(specialtyId && { specialtyId }),
        ...(search && { name: { contains: search, mode: "insensitive" } }),
      },
      include: { specialty: true },
    });
    res.json(doctors);
  } catch (err) {
    next(err);
  }
};

export const getDoctorById = async (req, res, next) => {
  try {
    const doctor = await prisma.doctor.findUniqueOrThrow({
      where: { doctorId: req.params.id },
      include: { specialty: true, doctorAffiliations: { include: { hospital: true } } },
    });
    res.json(doctor);
  } catch (err) {
    next(err);
  }
};

export const updateDoctor = async (req, res, next) => {
  try {
    const doctor = await prisma.doctor.update({
      where: { doctorId: req.params.id },
      data: req.body,
    });
    res.json(doctor);
  } catch (err) {
    next(err);
  }
};

export const deleteDoctor = async (req, res, next) => {
  try {
    await prisma.doctor.delete({ where: { doctorId: req.params.id } });
    res.status(204).send();
  } catch (err) {
    next(err);
  }
};