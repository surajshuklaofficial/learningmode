import React, { useState } from 'react';

import { ThemeModeSwitch } from './components';
import { Home } from './containers';
import { ThemeModeContext, FontProvider } from './contexts';

const App = () => {
    // const [mode, setMode] = useState('dark');
    const [darkModeOn, setDarkModeOn] = useState(true);

    const handleSwitchToggle = () => {
        setDarkModeOn(!darkModeOn);
    }

    return (

        <ThemeModeContext.Provider value={`${darkModeOn ? 'dark': 'light'}`}>
            <FontProvider >
                <div className={`${darkModeOn ? 'dark': 'light'} min-h-screen h-full`}> 
                    <ThemeModeSwitch darkModeOn={darkModeOn} handleSwitchToggle={handleSwitchToggle} />
                    <button onClick={() => print()}>Print</button>
                    <Home />
                </div>
            </FontProvider>
        </ThemeModeContext.Provider>
    )
}

export default App;