import Switch from 'react-switch';

const ThemeModeSwitch = ({darkModeOn, handleSwitchToggle}) => (
    <Switch
        checked={darkModeOn}
        onChange={handleSwitchToggle}
        offColor="#000000"
        onColor='#ffffff'
        onHandleColor="#ffffff"
        offHandleColor='#000000'
        handleDiameter={25}
        uncheckedIcon={false}
        checkedIcon={false}
        boxShadow="0px 1px 5px rgba(0, 0, 0, 0.6)"
        activeBoxShadow="0px 0px 1px 10px rgba(0, 0, 0, 0.2)"
        height={20}
        width={42}
        className="react-switch"
        id="material-switch"
    />
)

export default ThemeModeSwitch;