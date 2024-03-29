import React from 'react'

const Child = ({handler, message, onClose}) => {
    return (
        <>
            <div onClick={() => handler(message)}>Child</div>
            <button onClick={onClose}>Close Tab</button>
        </>
    )
}

export default Child;