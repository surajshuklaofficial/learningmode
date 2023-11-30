import React, { useState, useEffect, useContext } from 'react';

import { DropdownMenu } from '../../components';
import { ThemeModeContext } from '../../contexts';

const InputDetails = ({ data, setData }) => {
  const [selectedOption, setSelectedOption] = useState('experiences'); // Initialize the selected option state
  const [temp, setTemp] = useState([]);
  const [newData, setNewData] = useState({});
  const mode = useContext(ThemeModeContext);

  console.log(mode);

  useEffect(() => {
    setTemp(data[selectedOption] || []);

    // Reset 'newData' when the selected option changes
    setNewData({});
  }, [selectedOption, data]);

  const handleChange = (e, index) => {
    const { name, value } = e.target;

    // Update the 'temp' state with the modified item
    const updatedTemp = temp.map((item, i) =>
      i === index ? { ...item, [name]: value } : item
    );
    setTemp(updatedTemp);
  };

  const handleSubmit = (e, index) => {
    e.preventDefault();
    setData({ ...data, [selectedOption]: temp });
  };

  const handleAddChange = (e) => {
    setNewData({ ...newData, [e.target.name]: e.target.value });
  };

  const handleAdd = () => {
    // Create a new item with an 'id' based on the current length
    const newItem = { id: data[selectedOption].length + 1, ...newData };

    // Update the 'data' state with the new item
    setData({
      ...data,
      [selectedOption]: [...data[selectedOption], newItem],
    });

    // Reset 'newData' to an empty object
    setNewData({});
  };

  return (
    <section>
      <DropdownMenu
        setSelectedOption={setSelectedOption}
        selectedOption={selectedOption}
      />
      <form onSubmit={handleSubmit}>
        {temp.map((value, index) => (
          <div className='border' key={value.id}>
            {Object.keys(value).map((key) => (
              <input
                className={`${mode}`}
                key={key}
                name={key}
                value={value[key]}
                onChange={(e) => handleChange(e, index)}
              />
            ))}
          </div>
        ))}
        <div className='border'>
          {Object.keys(data[selectedOption][0]).map((key) => (
            <input
              className={`${mode}`}
              key={key}
              name={key}
              value={newData[key] || ''}
              placeholder={key}
              onChange={handleAddChange}
              required
            />
          ))}
        </div>
        <button>Edit</button>
        <button type='button' onClick={handleAdd}>
          Add
        </button>
      </form>
    </section>
  );
};

export default InputDetails;
