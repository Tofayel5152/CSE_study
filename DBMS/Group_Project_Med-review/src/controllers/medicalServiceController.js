import { prisma } from "../database/db.js";

export const createService = async (req, res, next) => {
  try {
    const { hospitalId, serviceName, description } = req.body;
    const service = await prisma.medicalService.create({
      data: { hospitalId, serviceName, description },
    });
    res.status(201).json(service);
  } catch (err) {
    next(err);
  }
};

export const getServicesByHospital = async (req, res, next) => {
  try {
    const services = await prisma.medicalService.findMany({
      where: { hospitalId: req.params.hospitalId },
    });
    res.json(services);
  } catch (err) {
    next(err);
  }
};

export const updateService = async (req, res, next) => {
  try {
    const service = await prisma.medicalService.update({
      where: { serviceId: req.params.id },
      data: req.body,
    });
    res.json(service);
  } catch (err) {
    next(err);
  }
};

export const deleteService = async (req, res, next) => {
  try {
    await prisma.medicalService.delete({ where: { serviceId: req.params.id } });
    res.status(204).send();
  } catch (err) {
    next(err);
  }
};