// array destructuring
const friends = ['a', 'b', 'c', 'd'];
const [ x, y, z, w ] = friends; // sequence is important
let [ x2, ...y2 ] = friends; // rest operator --> ...

console.log(x, y, z, w);
console.log(x2, y2);

// a way to switch values 
[y2, x2] = [x, y2];
console.log(x2, y2);

// object destructuring
const me = {
    name: 'Surajo',
    batch: 'A2',
    phone: 345643
}

const me2 = {
    name2: 'Surajo',
    batch2: 'A2',
    phone2: 345643
}
const me3 = {
    a: 'x',
    b: 'y',
    c: {d: 'z'}
}

const me4 = {
    a2: 'x',
    b2: 'y',
    c2: {d: 'z'}
}  

//me1
let {name, batch, mobile} = me; // sequence is not important while destructuring
console.log(name, batch, mobile); // mobile is undefined as it is not matching with any properties in me

//me2
const {name2, batch2, phone2} = me2;
console.log(name2, batch2, phone2);

// me3
const { a, b, c:{d:e} } = me3; // c, d are not defined as they are serving as matching for e
console.log(a, b, e);

//me4
const {b2, ...rest} = me4;
console.log(b2, rest);
