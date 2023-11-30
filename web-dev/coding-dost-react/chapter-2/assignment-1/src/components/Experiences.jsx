const Experiences = ({experiences}) => {
  return (
    <div>
    <h1>Experiences</h1>
    {experiences.map((experience, index) => (
      <div key={index}>
        <p>year: <span>experience.year</span></p>
        <p>company: <span>experience.company</span></p>
        <p>role: <span>experience.role</span></p>
      </div>
    ))}
  </div>
  )
}

export default Experiences;