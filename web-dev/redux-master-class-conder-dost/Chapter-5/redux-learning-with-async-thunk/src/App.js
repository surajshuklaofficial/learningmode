import React, { useState } from 'react';
import logo from './logo.svg';
import { Products } from './features/products/Products';
import { Carts } from './features/carts/Carts';
import './App.css';

function App() {
  console.log('hi');
  
  const [showCart, setShowCart] = useState(false);

  const cartToggler = () => {
    setShowCart(prevState => !prevState);
  }

  return (
    <div className="App">
      <button onClick={cartToggler}>Show Cart</button>
      {showCart && <Carts />}
      <Products />
    </div>
  );
}

export default App;
