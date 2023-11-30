const Skills = ({skills}) => {
  return (
    <div>
      <h1>Skills</h1>
      {skills.map((skill, index) =>(
        <div key={index}>
          <p>{skill}</p>
        </div>
      ))}
    </div>
  )
}

export default Skills;