import { useFont } from "../hooks";

const Education = ({education, handleDeleteButton}) => {
  const { fontSize, fontColor } = useFont();

  return (
    <div className="my-4" style={{fontSize, color: fontColor}}>
      <h3 className="text-2xl font-semibold">Education:</h3>
      <div className="ml-16">
        {education.map((element, index) => (
          <div className='border p-2' key={index}>
            <button onClick={(e) => handleDeleteButton('education', element.id)}>X</button>
            <p>{element?.place} : <span>{element?.name}</span></p>
          </div>
        ))}
      </div>
    </div>
  )
}

export default Education;