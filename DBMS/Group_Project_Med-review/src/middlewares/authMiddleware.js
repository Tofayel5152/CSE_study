import jwt from 'jsonwebtoken';
import { prisma } from "../database/db.js";

export const authMiddleware = async (req, res, next) => {
    let token;
    if (req.headers.authorization && req.headers.authorization.startsWith("Bearer")) {
        token = req.headers.authorization.split(" ")[1];
    } 
    else if (req.cookies?.jwt) {
        token = req.cookies.jwt;
    }

    if (!token) {
        return res.status(401).json({ message: "Not authorized, no token" });
    }

    try {
        const decoded = jwt.verify(token, process.env.JWT_SECRET);
        const user = await prisma.user.findUnique({
            where: { userId: decoded.id },
            select: {
                userId: true,
                firstName: true,
                lastName: true,
                email: true,
                phone: true,
                nid: true,
                role: true,
            }, 
        });

        if (!user) {
            return res.status(401).json({ message: "Not authorized, user not found" });
        }

        req.user = user;
    } catch (error) {
        console.error("Error in authMiddleware:", error);
        return res.status(401).json({ message: "Not authorized, token failed" });
    }
    next();
}