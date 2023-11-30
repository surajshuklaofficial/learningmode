import express from 'express';
import dotenv from 'dotenv';
import mongoose from 'mongoose';

import productRouter from './routes/products.js';
import userRouter from './routes/users.js';

// configuring environment variables
dotenv.config();

// creating a server
const server = express();

// adding middleware
server.use(express.json());



//db connection
main().catch(err => console.log(err));

async function main() {
  await mongoose.connect('mongodb://127.0.0.1:27017/ecommerceDB');
  console.log('database connected')
}

server.use('/products', productRouter);
server.use('/users', userRouter);


server.listen(process.env.PORT, () => {                  // this callback invokes while restarting the server (not while making a request)
    console.log('server started'); 
});