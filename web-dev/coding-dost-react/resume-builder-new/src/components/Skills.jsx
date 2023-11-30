import { useFont, useDataDispatch } from "../hooks";

const Skills = ({skills}) => {
  const { fontSize, fontColor } = useFont();
  const dispatch = useDataDispatch();
  return (
    <div className={`my-4`} style={{fontSize, color: fontColor}}>
      <h3 className="text-2xl font-semibold">Skills:</h3>
      <div className="ml-16">
        {skills.map((skill, index) =>(
          <div key={index}>
            <button onClick={() => dispatch({type: 'DELETE', payload: {category: 'skills', index: skill.id}})}>X</button>
            <p>{skill.skill}</p>
          </div>
        ))}
      </div>

    </div>
  )
}

export default Skills;