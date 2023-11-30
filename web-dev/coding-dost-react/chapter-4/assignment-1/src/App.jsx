import { useState } from "react";

import Child from "./Child";

const App = () => {
  const [enlargeImage, setEnlargeImage] = useState(false);
  const handleMouseOver = () => {
    setEnlargeImage(() => true);
  };
  const handleMouseOut = () => {
    setEnlargeImage(() => false);
  };

  const styles = { width: enlargeImage ? "250px" : "150px" };

  const handleButtonClick = () => {
    console.log("hi");
  };

  const handleButtonDoubleClick = (event) => {
    event.stopPropagation();
    event.preventDefault();
    alert("Double click");
  };

  const handleInputKeyPress = (event) => {
    console.log(event.key);
    event.key === "Enter" && alert("Enter key pressed");
  };

  const childHandler = (message) => {
    alert(message);
  };
  return (
    <div >
      <img
        src={
          "https://img.freepik.com/free-photo/painting-mountain-lake-with-mountain-background_188544-9126.jpg?w=1380&t=st=1696685388~exp=1696685988~hmac=5ad6a8bfadb75b29ea4018dc4a0a6745581c43e47264a3c535d53a397da89545"
        }
        alt="test-image"
        onMouseOver={handleMouseOver}
        onMouseOut={handleMouseOut}
        style={styles}
      />
      <button
        onClick={handleButtonClick}
        onDoubleClick={handleButtonDoubleClick}
      >
        Click Here
      </button>
      <input
        onFocus={() => console.log("Focus on text box")}
        onBlur={() => console.log("Out of text box")}
        onCut={() => alert("text cut")}
        onCopy={() => alert("text copy")}
        onPaste={() => alert("text paste")}
        onKeyDown={handleInputKeyPress}
      />

      <Child handler={childHandler} message="hello world" onClose={() => close()}/>
    </div>
  );
};

export default App;
