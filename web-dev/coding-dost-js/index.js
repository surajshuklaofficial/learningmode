// import './Product.js'; // when we want to run this file directly; to use es6 we have to write type='module in script tag of html while importing in html file

// named import 
// default import

// as keyword used for aliasing
// export { laptopPrice, quantity as quant}
// import { laptopPrice, quant} from './Product.js';

// to import all variables 
// import * as singleVariable from './Product.js';
// singleVariable.laptopPrice, singleVariable.quant

// top level await is also available

//IIFE is also used for modulor blocks 

// Closures means 'inner' function has an access to the variables of it's parent function
// and parameter of outer function even after outer function has returned

let outerFunction = function(outerParameter) {
    let innerFunction = function(){
        console.log(outerParameter)
    }
    return innerFunction
}

let innerFunc = outerFunction('outer parameter')
innerFunc()

// Closure does not make separate copy of outer variables 
// it just reference them

let counter = function(){
    let count = 0;
    let innerCounter = function(){
        return count = count + 1;
    }
    return innerCounter;
}

let innerCount = counter()
console.log(innerCount())
console.log(innerCount())