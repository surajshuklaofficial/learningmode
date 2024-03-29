import { Skills, Education, Experiences } from './';

const Resume = ({experiences, education, skills, children}) => {
  console.log(experiences, education, skills);
  console.log(children); // it is an array of objects
  return (
    <div>
        {children[0]}
        <div>
          {skills.length ? <Skills skills={skills} /> : null}
          {experiences.length ? <Experiences experiences={experiences} /> : null }
          {education.length ? <Education education={education} /> : null}
        </div>
    </div>
  )
}

export default Resume;