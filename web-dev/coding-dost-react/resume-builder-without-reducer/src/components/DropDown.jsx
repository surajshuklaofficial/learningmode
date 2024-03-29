import React, {useContext} from 'react';

import { ThemeModeContext } from '../contexts';

function DropdownMenu({ selectedOption, setSelectedOption}) {
    const mode = useContext(ThemeModeContext);

    const handleOptionChange = (event) => {
        setSelectedOption(event.target.value);
    };

    return (
        <div>
        <label htmlFor="myDropdown">Select an Option:</label>
        <select
            id="myDropdown"
            value={selectedOption}
            onChange={handleOptionChange}
            className={`${mode} rounded m-2 p-2`}
        >
            <option value="experiences">Experiences</option>
            <option value="education">Education</option>
            <option value="skills">Skills</option>
        </select>
        <p>Selected Option: {selectedOption}</p>
        </div>
    );
}

export default DropdownMenu;
