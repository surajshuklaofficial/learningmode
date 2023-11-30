import React from 'react'

const List = ({layout, items}) => {
  return (
    <div>
        {layout !== 'bullet' ? (
            <ol type={layout === 'numbered' ? null : 'a'}>
                {items.map((item) =>
                    <li>{item}</li>
                )}
            </ol>
        ) : (
            <ul>
                {items.map((item) =>
                    <li>{item}</li>
                )}
            </ul>
        )}
    </div>
  )
}

export default List