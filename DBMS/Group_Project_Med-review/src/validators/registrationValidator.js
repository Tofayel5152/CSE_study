import {z} from "zod";

export const registerSchema = z.object({
  username: z.string().min(8, "Username must be at least 8 characters long"),
  email: z.string().email("Invalid email address"),
  password: z.string().min(6, "Password must be at least 6 characters long"),
});