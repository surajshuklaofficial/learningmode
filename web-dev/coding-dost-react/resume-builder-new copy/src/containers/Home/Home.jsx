import React, { useState } from 'react';

import { InputDetails } from '../';
import { Resume } from '../../components';
import { resume } from '../../data';

const Home = () => {

  const [data, setData] = useState(resume);
  console.log(data);

  const handleDeleteButton = (c, index) => {
    const dataAfterDeletion = data[c]?.filter(x => x.id !== index);
    setData({...data, [c] : dataAfterDeletion})
  }

  return (
    <section className='m-4'>
      <Resume {...data} handleDeleteButton={handleDeleteButton}/>
      <InputDetails data={data} setData={setData}/>
    </section>
  )
}

export default Home;