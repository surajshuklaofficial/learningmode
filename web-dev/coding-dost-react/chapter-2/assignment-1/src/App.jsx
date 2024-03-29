import { useEffect } from 'react';
import { Resume } from './components';

const App = () => {
  const resume = {
    experiences : [ { year:2012, company:'xyz', role:'something' }],
    education:[ { school: "rpvv"}, { college: "dtu"}],
    skills : [ 'react js', 'node js']
  }

  return (
    <div>
      <Resume {...resume}> 
        <h1>Resume</h1>
      </Resume>
    </div>
  )
}

export default App;