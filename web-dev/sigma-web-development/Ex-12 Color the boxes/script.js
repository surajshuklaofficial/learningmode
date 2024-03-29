function randomNumber() {
  return Math.floor(Math.random() * 256);
}

function randomColor() {
  return `rgb(${randomNumber()},${randomNumber()},${randomNumber()})`;
}

Array.from(document.getElementsByClassName("box")).forEach((element) => {
  element.style.backgroundColor = randomColor();
});