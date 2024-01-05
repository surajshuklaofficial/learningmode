let a = prompt("Enter first number: ");

let b = prompt("Enter second number: ");

let operation = prompt("Enter operation(+, -, *, /): ");

let faultProbability = Math.random() * 100;

// function calc(num1, num2, operation) {
//     num1 = +num1;
//     num2 = +num2;
//     switch (operation) {
//         case '+':
//             return num1 + num2;
//         case '-': 
//             return num1 - num2;
//         case '*':
//             return num1 * num2;
//         case '/':
//             return num1 / num2;
//         default:
//             return 0;
//     }
// }

console.log(faultProbability, a, b);

let faultyObj = {
    "+": "-",
    "*": "+",
    "-": "/",
    "/": "**"
}

if (faultProbability < 10) {
    operation = faultyObj[operation];
}

// console.log(calc(a, b, operation));
console.log(eval(`${+a} ${operation} ${+b}`))