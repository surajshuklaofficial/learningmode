let arr1 = [1, 2, 3, 4]

// checking difference between map and filter
let arr2 = arr1.map( element => {if(element > 2) return element * 2});

console.log(arr2);
arr2 = arr2.filter(element => {if (element > 2) return element * 2});
console.log(arr2);

// flat 
let arr3 = [1, 2, 3, 4, [1, 2, 3, 4]]
console.log(arr3.flat(), arr3);