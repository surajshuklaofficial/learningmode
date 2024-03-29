import { useDataDispatch, useFont } from "../hooks";

const Education = ({education}) => {
  const { fontSize, fontColor } = useFont();

  const dispatch = useDataDispatch();
  return (
    <div className="my-4" style={{fontSize, color: fontColor}}>
      <h3 className="text-2xl font-semibold">Education:</h3>
      <div className="ml-16">
        {education.map((element, index) => (
          <div className='border p-2' key={index}>
            <button onClick={() => dispatch({type: 'DELETE', payload: {category: 'education', index: element.id}})}>X</button>
            <p>{element?.place} : <span>{element?.name}</span></p>
          </div>
        ))}
      </div>
    </div>
  )
}

export default Education;