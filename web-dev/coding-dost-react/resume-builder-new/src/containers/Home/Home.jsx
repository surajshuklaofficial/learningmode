import React, { useState, useReducer } from 'react';

import { InputDetails } from '../';
import { Resume } from '../../components';
import { resume } from '../../data';
import { DataDispatchContext } from '../../contexts';

const Home = () => {

  const dataReducer = (data, action) => {
    switch (action.type) {
      case 'DELETE':
        const dataAfterDeletion = data[action.payload.category]?.filter(x => x.id !== action.payload.index);
        console.log(data[action.payload.category], action.payload.index);
        return {...data, [action.payload.category] : dataAfterDeletion};

      default : 
        return {...data};
    }
  }
  // const [data, setData] = useState(resume);
  const [data, dispatch] = useReducer(dataReducer, resume);
  console.log(data);

  // const handleDeleteButton = (c, index) => {
  //   const dataAfterDeletion = data[c]?.filter(x => x.id !== index);
  //   setData({...data, [c] : dataAfterDeletion})
  // }

  return (
    <DataDispatchContext.Provider value={dispatch}>
      <section className='m-4'>
        <Resume {...data} />
        {/* <InputDetails data={data} setData={setData}/> */}
      </section>
    </DataDispatchContext.Provider>
  )
}

export default Home;