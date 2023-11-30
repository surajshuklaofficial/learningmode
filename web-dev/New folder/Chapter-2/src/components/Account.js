import { useState } from "react";
import { INCREMENT, DECREMENT, INCREMENTBYAMOUNT, DECREMENTBYAMOUNT } from "../constants";
import { useDispatch, useSelector } from "react-redux";
function Account() {
  console.log("Account");

  const [value, setValue] = useState(0);
  const amount = useSelector(store => store.account.amount);
  const dispatch = useDispatch();

  function increment() {
    dispatch({type: INCREMENT});
  }

  function decrement() {
    dispatch({type: DECREMENT});
  }

  function incrementByAmount (value) {
    dispatch({type: INCREMENTBYAMOUNT, payload: value});
  }

  function decrementByAmount (value) {
    dispatch({type: DECREMENTBYAMOUNT, payload: value});
  }

  return (
    <div className="card">
      <div className="container">
        <h4>
          <b>Account Component</b>
        </h4>
        <h3>Amount:${amount}</h3>
        <button onClick={increment}>Increment +</button>
        <button onClick={decrement}>Decrement -</button>
        <input type="text" onChange={(e) => setValue(+e.target.value)}></input>
        <button onClick={() => incrementByAmount(value)}>
          Increment By {value} +
        </button>
        <button onClick={() => decrementByAmount(value)}>
          Decrement By {value} -
        </button>
      </div>
    </div>
  );
}

export default Account;
