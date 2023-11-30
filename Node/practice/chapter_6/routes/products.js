import express from 'express';

import { createProduct, getAllProducts, getProduct, updateProduct, replaceProduct, deleteProduct} from '../controllers/products.js';

const router = express.Router();

// chaining of server object is possible
router.post('/', createProduct)
    .get('/', getAllProducts)
    .get('/:id', getProduct)
    .patch('/id', updateProduct)
    .put('/:id', replaceProduct)
    .delete('/:id', deleteProduct);

export default router;