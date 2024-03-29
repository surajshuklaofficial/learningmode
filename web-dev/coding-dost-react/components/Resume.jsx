import { useContext } from "react";

import { Skills, Education, Experiences } from "./";
import ThemeModeContext from "../context/themeMode";

const Resume = ({ experiences, education, skills, children }) => {
  const mode = useContext(ThemeModeContext);

  return (
    <div className="Resume">
      {children[0]}
      <div>
        {skills.length ? <Skills skills={skills} /> : null}
        {experiences.length ? <Experiences experiences={experiences} /> : null}
        {education.length ? <Education education={education} /> : null}
        <button className={`${mode}`} onClick={() => print()}>
          Print Resume
        </button>
      </div>
    </div>
  );
};

export default Resume;
