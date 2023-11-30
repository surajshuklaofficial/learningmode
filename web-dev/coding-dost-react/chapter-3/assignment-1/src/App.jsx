import React from 'react';

import List from './List';

const App = () => {
    const items = ['orange', 'apple', 'banana']
    return (
        <div>
            <List layout={"bullet"} items={items} />
        </div>
    )
}

export default App;