import React, { useEffect, useState } from 'react';
import { useSelector, useDispatch } from 'react-redux';
import styles from './Products.module.css';
import Card from './Card';
import { fetchAsync } from './productsSlice';

export function Products() {
  const products = useSelector(state => state.product.products);
  const dispatch = useDispatch();

  useEffect(() => {
    dispatch(fetchAsync());
  }, [])

  return (
    <div>
      {
        products && products.map((product) => (
          <Card product={product} key={product.id} dispatch={dispatch}/>
        ))
      }
    </div>
  );
}
