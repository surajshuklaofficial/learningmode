import { useState, useEffect } from 'react';

const Assign1 = () => {
    const [time, setTime] = useState(new Date());
    const [minute, setMinute] = useState(time.getMinutes());

    useEffect(() => {
        setTimeout(() => {
            setTime(new Date());
            if (time.getMinutes() !== minute) {
                console.log('One Minute Passed');
                setMinute(time.getMinutes());
            }
        }, 1000)
    },[time])

    return (
        <div>
           {time.getHours()} : {time.getMinutes()} : {time.getSeconds()} 
        </div>
    )
}

export default Assign1;