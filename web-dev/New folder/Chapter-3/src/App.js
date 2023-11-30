import './App.css';
import Account from './components/Account';
import Admin from './components/Admin';
import Bonus from './components/Bonus';
import Reward from './components/Reward';
import { useSelector } from 'react-redux';

function App() {

  const amount = useSelector(state => state.account.amount);
  const bonus = useSelector(state => state.bonus.points);

  return (
    <div className="App">
      <h4>App</h4>
      <h3>Current Amount : {amount}</h3>
      <h3>Total Bonus : {bonus}</h3>

      <Account></Account>
      <Bonus></Bonus>
      <Reward></Reward>
      <Admin />
    </div>
  );
}

export default App;
