// ---------- selection of element --------------
let querySelector = document.querySelector('h2'); // return NodeList(similar to array)
console.log(querySelector)

// these are outdated methods - all return HTML collections
let byTag = document.getElementsByTagName('p') // return HTML collection
console.log(byTag)

// ------------- updating and changing element --------------------

let heading = document.querySelector('#heading')
console.log(heading)

heading.innerHTML = '<p>hello</p>';
heading.innerHTML += '<p>hello</p>';

// heading.innerText = '<p>hello</p>';

// ------------ add new element --------------------
let ul = document.querySelector('ul');

l5 = document.createElement('li');
l5.textContent = 'Hello';
ul.prepend(l5)

// remove element
ul.removeChild(l5);

