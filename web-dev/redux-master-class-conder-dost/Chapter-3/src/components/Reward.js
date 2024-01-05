import { useDispatch, useSelector } from 'react-redux';

import { increment, incrementByAmount } from '../reducers/reward';

function Reward() {
  const reward = useSelector(state => state.reward.points);
  const dispatch = useDispatch();
  return (
    <div className="card">
      <div className="container">
        <h4>
          <b>Reward Component</b>
        </h4>
        <h3>Total Point : ${reward}</h3>

        <button onClick={() => dispatch(increment())}>Increment +</button>
        <button onClick={() => dispatch(incrementByAmount(8))}>IncrementByAmount +</button>
      </div>
    </div>
  );
}

export default Reward;
