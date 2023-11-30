
const Education = ({education}) => {
  return (
    <div>
      <h1>Education</h1>
      {education.map((element, index) => (
        <div key={index}>
          {Object.keys(element)} : {Object.values(element)}
        </div>
      ))}
    </div>
  )
}

export default Education;