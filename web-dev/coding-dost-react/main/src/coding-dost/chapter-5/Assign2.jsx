import { useState, useEffect } from 'react';

const Assign2 = () => {
    const [timeInterval, setTimeInterval] = useState(0);
    const [timerOn, setTimerOn] = useState(false);

    useEffect(() => {
        let intervalId;

        if (timerOn) {
            intervalId = setInterval(() => {
                setTimeInterval((prevInterval) => prevInterval + 1);
            }, 1000);
        } else {
            clearInterval(intervalId);
        }

        return () => {
            clearInterval(intervalId);
        };
    }, [timerOn]);

    const handleResetClick = () => {
        setTimeInterval(0);
    };

    const handleStartStopClick = () => {
        setTimerOn(!timerOn);
    };

    return (
        <div>
            {timeInterval}
            <button onClick={handleStartStopClick}>{timerOn ? 'Stop' : 'Start'}</button>
            <button onClick={handleResetClick}>Reset</button>
        </div>
    );
};

export default Assign2;

/*
1. The function inside useEffect runs when the component is initially mounted (first render).

2. If you provide a dependency array ([] or with dependencies), the function inside useEffect runs again only if one or more dependencies have changed. It doesn't run on every render unless the specified dependencies change.

3. When the function inside useEffect runs again (due to changes in dependencies or initial mount), React compares the current dependency values with their previous values to determine if it should run the effect.

4. If the effect runs again, React first cleans up the previous effect (if any) by executing the cleanup function returned by the previous useEffect.

5. After cleaning up the previous effect, React runs the new effect function with the updated state or props.

*/