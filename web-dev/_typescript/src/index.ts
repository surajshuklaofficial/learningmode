type Sum<T extends number> = (num1: T, num2: T) => T;

const sum : Sum<string> = function(num1, num2){
    return  num1 + num2;
}

console.log(sum("suraj", "shukla"));
