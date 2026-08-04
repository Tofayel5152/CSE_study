import { prisma } from "../database/db.js";
import bcrypt from "bcrypt";
import generateToken from "../utils/generatetoken.js";

const register = async (req, res) => {
  const {
    firstName,
    lastName,
    email,
    phone,
    nid,
    password
  } = req.body;

  const userExists = await prisma.user.findFirst({
    where: {
      OR: [
        { email },
        { phone },
        { nid }
      ]
    }
  });

  if (userExists) {
    return res.status(400).json({ error: "User already exists" });
  }

  // Hash the password before storing it in the database
  const salt = await bcrypt.genSalt(10);
  const hashedPassword = await bcrypt.hash(password, salt);
  

  const user = await prisma.user.create({
    data: {
      firstName,
      lastName,
      email,
      phone,
      nid,
      passwordHash: hashedPassword
    }
  });

  res.status(201).json({ message: "User registered successfully", user });

}

const login = async ( req, res ) => {
  const {email,password} = req.body;
  
  //Check if user email exists
  const user = await prisma.user.findUnique({
    where: {
      email: email
    }
  });

  if(!user){
    return res.status(400).json({error: "Invalid email or password"});
  }

  //verify password
  const isPasswordValid = await bcrypt.compare(password, user.passwordHash);
  
  if(!isPasswordValid){
    return res.status(400).json({error: "Invalid email or password"});
  }

  const token = generateToken(user.userId, res); 

  res.status(201).json({ 
    status: "success", 
    data:{
      user: {
        id: user.id,
        name: user.firstName+ " " +user.lastName,
        email: user.email,
        phone: user.phone,
        nid: user.nid
      },
      token,
    }
  });
}

const logout = (req, res) => {
  res.cookie("jwt","",{
    expires: new Date(0),
  })
  res.status(200).json({
    status: "success",
    message: "User logged out successfully"
  });
}

const profile = async (req, res) => {

  res.status(200).json({
    status: "success",
    data: {
      user: {
        id: req.user.userId,
        name: req.user.firstName + " " + req.user.lastName,
        email: req.user.email,
        phone: req.user.phone,
        nid: req.user.nid,
      },
    },
  });
};

export { register, login, logout, profile };