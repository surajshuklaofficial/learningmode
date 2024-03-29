import { useContext } from 'react';

import { FontContext } from '../contexts';

// Create a custom hook for using the context
const useFont = () => {
  return useContext(FontContext);
}

export default useFont;