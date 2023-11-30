import React, {useContext} from 'react';

import { Skills, Education, Experiences } from "./";
import { useFont } from '../hooks';
import { ThemeModeContext } from '../contexts';

const Resume = ({skills, education, experiences, handleDeleteButton}) => {

  const { fontSize, setFontSize, fontColor, setFontColor } = useFont();
  const mode = useContext(ThemeModeContext);

  return (
    <div className='border p-4'>
      <h1 className='text-4xl font-bold m-auto'>Resume</h1>
      <Skills skills={skills} handleDeleteButton={handleDeleteButton}/>
      <Education education={education} handleDeleteButton={handleDeleteButton}/>
      <Experiences experiences={experiences} handleDeleteButton={handleDeleteButton}/>

      <form>
        <label htmlFor="fontSize">Font Size:</label>
        <input
          className={`${mode} px-2`}
          type="text"
          id="fontSize"
          value={fontSize}
          onChange={(e) => setFontSize(e.target.value)}
        />
        <label htmlFor="fontColor">Font Color:</label>
        <input
          className={`${mode} px-2`}
          type="text"
          id="fontColor"
          value={fontColor}
          onChange={(e) => setFontColor(e.target.value)}
        />
      </form>
    </div>
  )
}

export default Resume;