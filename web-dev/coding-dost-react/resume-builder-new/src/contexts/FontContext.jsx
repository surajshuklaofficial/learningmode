import React, { createContext, useContext, useState } from 'react';

// Create a context
const FontContext = createContext();

// Create a FontProvider component
const FontProvider = ({ children }) => {
  const [fontSize, setFontSize] = useState('16px');
  const [fontColor, setFontColor] = useState('black');

  return (
    <FontContext.Provider value={{ fontSize, setFontSize, fontColor, setFontColor }}>
      {children}
    </FontContext.Provider>
  );
}

export default FontProvider;
export { FontContext };
// // Create a custom hook for using the context
// export function useFont() {
//   return useContext(FontContext);
// }
