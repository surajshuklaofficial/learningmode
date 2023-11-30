const Experiences = ({experiences, handleDeleteButton}) => {

  return (
    <div className="my-4">
      <h3 className="text-2xl font-semibold">Experiences:</h3>
      <div className="ml-16 ">
        {experiences?.map((experience, index) => (
          <div className='border p-2' key={experience.id}>
            <button onClick={(e) => handleDeleteButton('experiences', experience.id)}>X</button>
            <p>year: <span>{experience?.year}</span></p>
            <p>company: <span>{experience?.company}</span></p>
            <p>role: <span>{experience?.role}</span></p>
          </div>
        ))}
      </div>
  </div>
  )
}

export default Experiences;