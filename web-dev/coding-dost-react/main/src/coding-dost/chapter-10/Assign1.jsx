import React from 'react';
import useCounter from './useCounter'; // Import the custom hook

function Counter() {
  const [count, increment, decrement] = useCounter(0); // Initialize with an initial value of 0

  return (
    <div>
      <p>Count: {count}</p>
      <button onClick={increment}>Increment</button>
      <button onClick={decrement}>Decrement</button>
    </div>
  );
}

export default Counter;
