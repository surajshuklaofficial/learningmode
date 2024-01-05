import { useState } from 'react';
import { useDispatch, useSelector } from 'react-redux';

import {increment, decrement, incrementByAmount, fetchUserAccount} from '../slices/accountSlice';

function Account() {
  const amount = useSelector(state => state.account.amount);
  const dispatch = useDispatch();

  const [value, setValue] = useState(0);

  return (
    <div className="card">
      <div className="container">
        <h4>
          <b>Account Component</b>
        </h4>
        <h3>Amount:${amount}</h3>
        <button onClick={() => dispatch(increment())}>Increment +</button>
        <button onClick={() => dispatch(decrement())}>Decrement -</button>
        <input type="text" onChange={(e) => setValue(+e.target.value)}></input>
        <button onClick={() => dispatch(incrementByAmount(value))}>
          Increment By {value} +
        </button>
        <button onClick={() => dispatch(fetchUserAccount(1))}>
          Init User
        </button>
      </div>
    </div>
  );
}

export default Account;
