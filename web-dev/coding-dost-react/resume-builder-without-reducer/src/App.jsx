import React, { useState } from 'react';

import { ThemeModeSwitch } from './components';
import { Home } from './containers';
import { resume } from './data';
import { ThemeModeContext } from './contexts';


const App = () => {
    // const [mode, setMode] = useState('dark');
    const [darkModeOn, setDarkModeOn] = useState(true);

    console.log(resume);

    const handleSwitchToggle = () => {
        setDarkModeOn(!darkModeOn);
    }

    return (

        <ThemeModeContext.Provider value={`${darkModeOn ? 'dark': 'light'}`}>
            <div className={`${darkModeOn ? 'dark': 'light'} min-h-screen h-full`}> 
                <ThemeModeSwitch darkModeOn={darkModeOn} handleSwitchToggle={handleSwitchToggle} />
                <button onClick={() => print()}>Print</button>
                <Home {...resume}/>
            </div>
        </ThemeModeContext.Provider>
    )
}

export default App;