import express from 'express';
import fs from 'fs';

//fetching data from the database
const data = JSON.parse(fs.readFileSync('data.json', 'utf8'));
const products = data.products;
// creating a server
const server = express();

// adding middleware
server.use(express.json());

// C R U D operations

// post POST create product
server.post('/products', (req, res) => {
    const new_product = req.body; // req.body will be meaningful only if express.json() middleware is used otherwise undefined
    products.push(new_product);
    res.status(201).json({message: 'created successfully!'})
});

// get GET products
server.get('/products', (req, res) => {
    console.log('fetching all products');
    res.status(200).json(products); // if data to be sent is more than one than it should be sent as an array; products will be an array
});

// get GET single product
server.get('/products/:id', (req, res) => {   
    const id = +req.params.id;    // req.params.id will be string by default; preadding + will make it int
    console.log("fetching single product");
    const product = products.find( p => p.id === id);
    res.status(200).json(product);
});

// update UPDATE updating existing data
server.patch('/products/:id', (req, res) => {
    const id = +req.params.id;
    const productIndex = products.findIndex(p => p.id === id);
    const product = products[productIndex];
    products.splice(productIndex, 1, { ... product, ...req.body}); // left spread opeator will overwrite right one
    res.status(200).json(products[productIndex]);
});

// update UPDATE overwrting existing data
server.put('/products/:id', (req, res) => {
    const id = +req.params.id;
    const productIndex = products.findIndex(p => p.id === id);
    const product = products[productIndex];
    products.splice(productIndex, 1, { id, ...req.body});
    res.status(200).json(products[productIndex]);
});

// delete DELETE deleting data
server.delete('/products/:id', (req, res) => {
    const id = +req.params.id;
    const productIndex = products.findIndex(p => p.id === id);
    const product = products[productIndex];
    products.splice(productIndex, 1);
    res.status(200).json(product);
});


const port = 8080;
server.listen(port, () => {                  // this callback invokes while restarting the server (not while making a request)
    console.log('server started'); 
});