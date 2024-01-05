import React, { useEffect, useState } from 'react';
import { useSelector, useDispatch } from 'react-redux';
import Card from './Card';
import { fetchAsync } from './cartsSlice';

export function Carts() {
  const items = useSelector(state => state.cart.items);
  const dispatch = useDispatch();

  useEffect(() => {
    dispatch(fetchAsync());
  }, []);

  return (
    <div>
      {
        items.map((item) => (
          <Card cartProduct={item} key={item.id}/>
        ))
      }
    </div>
  );
}
