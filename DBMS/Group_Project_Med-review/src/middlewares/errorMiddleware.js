export const notFound = (req, res, next) => {
  res.status(404).json({ message: `Route not found: ${req.originalUrl}` });
};

export const errorHandler = (err, req, res, next) => {
  console.error(err);

  // Prisma unique constraint violation
  if (err.code === "P2002") {
    return res.status(409).json({ message: `Duplicate value for: ${err.meta?.target}` });
  }

  // Prisma record not found
  if (err.code === "P2025") {
    return res.status(404).json({ message: "Record not found" });
  }

  res.status(err.statusCode || 500).json({ message: err.message || "Server error" });
};