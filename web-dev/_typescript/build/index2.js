"use strict";
// let x : readonly any[] = [1, 3, 4, 5];
// x.forEach(element => 
//     console.log(element)
// );
// let y : [a: number, b: number] = [1, 3];
// const [a, b] = y; // no need for this => const [a, b]: [number, number] = y;
// const student: {id: number, name: string, active:boolean} = {
//     id: 5,
//     name: "suraj",
//     active: true
// }
// const car = {
//     type: "Toyota",
//   };
//   car.type = "Ford"; // no error
// //   car.type = 2; // Error: Type 'number' is not assignable to type 'string'.
// console.log(x, a);
// enum CardinalDirections {
//     North,
//     East=5,
//     South,
//     West
//   };
//   let currentDirection = CardinalDirections.West;
//   // North is the first value so it logs '0'
//   console.log(currentDirection);
let json = JSON.parse("55");
console.log(typeof json);
json = "suraj";
console.log(typeof json);
function printStatusCode(code) {
    console.log(`My status code is ${typeof code === "string" ? code.toUpperCase() : code}.`); // error: Property 'toUpperCase' does not exist ontype 'string | number'.
}
printStatusCode("Not found!");
function createPair(v1, v2) {
    return [v1, v2];
}
console.log(createPair('hello', 42)); // ['hello', 42]
