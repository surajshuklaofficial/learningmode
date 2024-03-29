import express from 'express';

import productRouter from './routes/products.js';
import userRouter from './routes/users.js';

// creating a server
const server = express();

// adding middleware
server.use(express.json());

server.use('/products', productRouter);
server.use('/users', userRouter);

// C R U D operations
// // chaining of server object is possible
// server.post('/products', createProduct)
//     .get('/products', getAllProducts)
//     .get('/products/:id', getProduct)
//     .patch('/products/:id', updateProduct)
//     .put('/products/:id', replaceProduct)
//     .delete('/products/:id', deleteProduct);


const port = 8080;
server.listen(port, () => {                  // this callback invokes while restarting the server (not while making a request)
    console.log('server started'); 
});