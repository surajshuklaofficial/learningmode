import { useState } from 'react';
import { INCREMENTBONUS } from '../constants';
import { useDispatch, useSelector } from 'react-redux';

function Bonus() {
  console.log("Bonus");

  const points = useSelector(state => state.bonus.points.value);
  const dispatch = useDispatch();

  const increment = () => {
    dispatch({type: INCREMENTBONUS});
  };

  return (
    <div className="card">
      <div className="container">
        <h4>
          <b>Bonus Component</b>
        </h4>
        <h3>Total Point : ${points}</h3>

        <button onClick={increment}>Increment +</button>
      </div>
    </div>
  );
}

export default Bonus;
