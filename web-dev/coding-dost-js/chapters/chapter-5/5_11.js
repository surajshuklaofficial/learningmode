let ul = document.querySelector("ul");

ul.addEventListener(
  "click",
  (e) => {
    console.log("ul listener", e.target);
    console.log(e.target.nodeName);

    // delegation : Instead of attaching event handlers to individual child elements, you attach a single event handler to a common ancestor element (typically a parent or container element).
    if (e.target.nodeName === "LI") {
      console.log(e.target.innerHTML);
    }
  },
  true
);

let liElements = document.querySelectorAll("li");
liElements.forEach((li) => {
  li.addEventListener("click", (e) => {
    // e.stopPropagation();
    // console.log('li listener', e.target);
    // console.log('li', e.target.nodeName);
  });
});
