import { z } from "zod";
// / creating a schema for strings
const mySchema = z.string();
// parsing
mySchema.parse("tuna"); // => "tuna"
// mySchema.parse(12); // => throws ZodError
// "safe" parsing (doesn't throw error if validation fails)
mySchema.safeParse("tuna"); // => { success: true; data: "tuna" }
const a = mySchema.safeParse(12); // => { success: false; error: ZodError }
const User = z.object({
    username: z.string(),
});
User.parse({ username: "Ludwig" });
console.log(User);
// { username: string }
