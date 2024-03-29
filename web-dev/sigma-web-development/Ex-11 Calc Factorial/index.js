function factorial(n) {
    console.log(n)
    if (n === 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

console.log(factorial(5))

// let arr = [];
// let n = 5;
// while (n > 1) {
//     arr.push(n);
//     n--;
// }

let arr = Array(5).keys();
console.log(arr)

// console.log(arr.reduce((acc, x) => acc * x, 1));
