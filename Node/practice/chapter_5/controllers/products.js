import fs from 'fs';

//fetching data from the database
const data = JSON.parse(fs.readFileSync('data.json', 'utf8'));
const products = data.products;

const createProduct = (req, res) => {
    const new_product = req.body; // req.body will be meaningful only if express.json() middleware is used otherwise undefined
    products.push(new_product);
    res.status(201).json({message: 'created successfully!'})
}

const getAllProducts = (req, res) => {
    console.log('fetching all products');
    res.status(200).json(products); // if data to be sent is more than one than it should be sent as an array; products will be an array
}

const getProduct = (req, res) => {   
    const id = +req.params.id;    // req.params.id will be string by default; preadding + will make it int
    console.log("fetching single product");
    const product = products.find( p => p.id === id);
    res.status(200).json(product);
}

const updateProduct = (req, res) => {
    const id = +req.params.id;
    const productIndex = products.findIndex(p => p.id === id);
    const product = products[productIndex];
    products.splice(productIndex, 1, { ... product, ...req.body}); // left spread opeator will overwrite right one
    res.status(200).json(products[productIndex]);
}

const replaceProduct = (req, res) => {
    const id = +req.params.id;
    const productIndex = products.findIndex(p => p.id === id);
    const product = products[productIndex];
    products.splice(productIndex, 1, { id, ...req.body});
    res.status(200).json(products[productIndex]);
}

const deleteProduct = (req, res) => {
    const id = +req.params.id;
    const productIndex = products.findIndex(p => p.id === id);
    const product = products[productIndex];
    products.splice(productIndex, 1);
    res.status(200).json(product);
}

export { createProduct, getAllProducts, getProduct, updateProduct, replaceProduct, deleteProduct};