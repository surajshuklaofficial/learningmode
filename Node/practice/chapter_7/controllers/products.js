import fs from 'fs';

import Products from '../model/products.js';

const createProduct = (req, res) => {
    const new_product = req.body; 
    const products = new Products(new_product);
    products.save();
    res.status(201).json({message: 'created successfully!'})
}

const getAllProducts = async (req, res) => {
    const data = await Products.find();
    console.log(data)
    res.status(200).json(data); // if data to be sent is more than one than it should be sent as an array; products will be an array
}

const getProduct = async (req, res) => {   
    const id = req.params.id;    // req.params.id will be string by default; preadding + will make it int
    const data = await Products.findById({ _id: id});
    res.status(200).json(data);
}

const updateProduct = async (req, res) => {

    const id = req.params.id; 
    const data = await Products.findOneAndUpdate({_id: id}, { ...req.body});
    res.status(200).json(data);
}

const replaceProduct = async (req, res) => {
    const id = req.params.id; 
    const data = await Products.findOneAndReplace({_id: id}, { ...req.body});
    res.status(200).json(data);
}

const deleteProduct = async (req, res) => {
    const id = req.params.id;
    const product = await Products.findByIdAndDelete({_id: id});
    res.status(200).json(product);
}

export { createProduct, getAllProducts, getProduct, updateProduct, replaceProduct, deleteProduct};