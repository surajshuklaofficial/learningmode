import { useDispatch, useSelector } from 'react-redux';

import { increment, decrement } from '../slices/bonusSlice';

function Bonus() {
  const bonus = useSelector(state => state.bonus.points);
  const dispatch = useDispatch();
  return (
    <div className="card">
      <div className="container">
        <h4>
          <b>Bonus Component</b>
        </h4>
        <h3>Total Point : ${bonus}</h3>

        <button onClick={() => dispatch(increment())}>Increment +</button>
        <button onClick={() => dispatch(decrement())}>Increment -</button>
      </div>
    </div>
  );
}

export default Bonus;
