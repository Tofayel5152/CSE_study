import { prisma } from "../database/db.js";

// Reusable helper — call this from other controllers to record actions
// e.g. await logAction({ userId: req.user.userId, action: "DELETE_REVIEW", severity: "WARNING", details: "...", ipAddress: req.ip });
export const logAction = async ({ userId, action, severity = "INFO", details, ipAddress }) => {
  try {
    await prisma.systemLog.create({
      data: { userId, action, severity, details, ipAddress },
    });
  } catch (err) {
    // Logging should never crash the main request
    console.error("Failed to write system log:", err);
  }
};

// Admin: list logs, with optional filters
export const getLogs = async (req, res, next) => {
  try {
    const { severity, userId, action } = req.query;
    const logs = await prisma.systemLog.findMany({
      where: {
        ...(severity && { severity }),
        ...(userId && { userId }),
        ...(action && { action: { contains: action, mode: "insensitive" } }),
      },
      include: { user: { select: { firstName: true, lastName: true, email: true } } },
      orderBy: { createdAt: "desc" },
    });
    res.json(logs);
  } catch (err) {
    next(err);
  }
};

// Admin: get a single log entry
export const getLogById = async (req, res, next) => {
  try {
    const log = await prisma.systemLog.findUniqueOrThrow({
      where: { logId: req.params.id },
    });
    res.json(log);
  } catch (err) {
    next(err);
  }
};

// Admin: delete a log entry
export const deleteLog = async (req, res, next) => {
  try {
    await prisma.systemLog.delete({ where: { logId: req.params.id } });
    res.status(204).send();
  } catch (err) {
    next(err);
  }
};