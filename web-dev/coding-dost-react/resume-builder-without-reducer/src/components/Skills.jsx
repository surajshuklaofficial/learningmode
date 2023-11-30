const Skills = ({skills, handleDeleteButton}) => {
  return (
    <div className="my-4">
      <h3 className="text-2xl font-semibold">Skills:</h3>
      <div className="ml-16">
        {skills.map((skill, index) =>(
          <div key={index}>
            <button onClick={(e) => handleDeleteButton('skills', skill.id)}>X</button>
            <p>{skill.skill}</p>
          </div>
        ))}
      </div>

    </div>
  )
}

export default Skills;