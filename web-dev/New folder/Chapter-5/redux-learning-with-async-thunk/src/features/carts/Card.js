// CartProductCard.js

import React, { useState } from 'react';
import './Card.css';
import { useDispatch } from 'react-redux';
import { deleteAsync, updateAsync } from './cartsSlice';

const CartProductCard = ({ cartProduct }) => {
  const [quantity, setQuantity] = useState(cartProduct.quantity);
  const dispatch = useDispatch();

  const handleIncrease = (id) => {
    setQuantity((quantity) => quantity + 1);
    dispatch(updateAsync({id, change: quantity + 1}))
  };

  const handleDecrease = (id) => {
    if (quantity > 1) {
      setQuantity(quantity => quantity - 1);
      dispatch(updateAsync({id, change: quantity - 1}))
    }
  };

  return (
    <div className="cart-product-card">
      <img src={cartProduct.thumbnail} alt={cartProduct.title} className="cart-product-image" />
      <div className="cart-product-content">
        <h2 className="cart-product-title">{cartProduct.title}</h2>
        <p className="cart-product-description">{cartProduct.description}</p>
        <p className="cart-product-price">${cartProduct.price}</p>
        <div className="quantity-control">
          <button className="quantity-button" onClick={() => handleDecrease(cartProduct.id)}>-</button>
          <input type="number" className="quantity-input" value={quantity} readOnly />
          <button className="quantity-button" onClick={() => handleIncrease(cartProduct.id)}>+</button>
        </div>
      </div>
      <button onClick={() => dispatch(deleteAsync(cartProduct.id))}>X</button>
    </div>
  );
};

export default CartProductCard;
