// Card.js

import React from 'react';
import './Card.css';
import { addAsync } from '../carts/cartsSlice';

const Card = ({ product, dispatch }) => {
  return (
    <div className="card">
      <img src={product?.thumbnail} alt={product?.title} className="card-image" />
      <div className="card-content">
        <h2 className="card-title">{product?.title}</h2>
        <p className="card-description">{product?.description}</p>
        <p className="card-price">${product?.price}</p>
      </div>
      <button onClick={() => dispatch(addAsync({id: product.id, thumbnail: product.thumbnail, title: product?.title, price: product?.price, quantity: 1}))}>Add to Cart</button>
    </div>
  );
};


export default Card;
