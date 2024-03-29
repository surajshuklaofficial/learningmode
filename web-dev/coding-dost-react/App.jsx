import { useContext, useState } from "react";
import Switch from "react-switch";

import ThemeModeContext from "./context/themeMode";
import { Resume } from "./components";

const App = () => {
  const theme = useContext(ThemeModeContext); // this is used to get value stored in ThemeModeContext
  const [mode, setMode] = useState(theme);
  const [darkModeOn, setDarkModeOn] = useState(false);

  const resume = {
    experiences: [{ year: 2012, company: "xyz", role: "something" }],
    education: [{ school: "rpvv" }, { college: "dtu" }],
    skills: ["react js", "node js"],
  };

  const handleSwitch = () => {
    setMode(!darkModeOn ? "lightMode" : "darkMode");
    setDarkModeOn(!darkModeOn);
  };

  return (
    <ThemeModeContext.Provider value={mode}>
      <div className={`${mode} bg-black`}>
        <Switch onChange={handleSwitch} checked={darkModeOn} />
        <Resume {...resume}>
          <h1>Resume</h1>
        </Resume>
      </div>
    </ThemeModeContext.Provider>
  );
};

export default App;
