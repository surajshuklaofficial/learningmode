import React from 'react';

import { Skills, Education, Experiences } from "./";

const Resume = ({skills, education, experiences, handleDeleteButton}) => {

  return (
    <div className='border p-4'>
      <h1 className='text-4xl font-bold m-auto'>Resume</h1>
      <Skills skills={skills} handleDeleteButton={handleDeleteButton} />
      <Education education={education} handleDeleteButton={handleDeleteButton}/>
      <Experiences experiences={experiences} handleDeleteButton={handleDeleteButton}/>
    </div>
  )
}

export default Resume;