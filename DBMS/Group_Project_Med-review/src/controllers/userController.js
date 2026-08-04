import { prisma } from "../database/db.js";

export const getAllUsers = async (req, res) => {
  try {
    const users = await prisma.user.findMany();

    res.json({
      status: "success",
      data: {
        users: users.map((user) => ({
          id: user.userId,
          name: user.firstName + " " + user.lastName,
          email: user.email,
          phone: user.phone,
          nid: user.nid,
        })),
      }
    });
  } catch (error) {
    res.status(500).json({
      success: false,
      message: error.message,
    });
  }
};

export const getUserById = async (req, res) => {
  try {
    const user = await prisma.user.findUnique({
      where: {
        userId: req.params.id,
      },
    });

    if (!user) {
      return res.status(404).json({
        message: "User not found",
      });
    }

    res.json({
      status: "success",
      data: {
        name: user.firstName + " " + user.lastName,
        email: user.email,
        phone: user.phone,
        nid: user.nid,
      }
    });
  } catch (error) {
    res.status(500).json({
      success: false,
      message: error.message,
    });
  }
};

export const updateUser = async (req, res) => {
  try {
    const { firstName, lastName, email, phone, nid } = req.body;

    const user = await prisma.user.update({
      where: {
        userId: req.params.id,
      },
      data: {
        firstName,
        lastName,
        email,
        phone,
        nid,
      },
    });

    res.json({
      status: "success",
      data: {
        name: user.firstName + " " + user.lastName,
        email: user.email,
        phone: user.phone,
        nid: user.nid,
      }
    });
  } catch (error) {
    res.status(500).json({
      success: false,
      message: error.message,
    });
  }
};

export const deleteUser = async (req, res) => {
  try {
    await prisma.user.delete({
      where: {
        userId: req.params.id,
      },
    });

    res.json({
      success: true,
      message: "User deleted",
    });
  } catch (error) {
    res.status(500).json({
      success: false,
      message: error.message,
    });
  }
};