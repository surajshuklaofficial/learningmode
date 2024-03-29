import { configureStore } from '@reduxjs/toolkit';
import productsReducer from '../features/products/productsSlice';
import cartReducer from '../features/carts/cartsSlice';

export const store = configureStore({
  reducer: {
    product: productsReducer,
    cart: cartReducer
  },
});
