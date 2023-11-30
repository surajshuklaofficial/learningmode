import mongoose from 'mongoose';

const productSchema = new mongoose.Schema({
    title: {type: String, required: true, unique: true},
    description: String,
    price: {type: Number, required: true, min: [0, "can't be less than 0"]},
    discountPercentage: {type: Number, min: [0, "can't be less than 0"], max: [100, "can't be greater than 100"]},
    rating: {type:Number, default: 0, min: [0, "can't be less than 0"], max: [5, "can't be greater than 5"]},
    brand: {type: String, required: true},
    category: {type: String, required: true},
    thumbnail: {type: String, required: true},
    images: [ String ]
});

export default mongoose.model('Products', productSchema);