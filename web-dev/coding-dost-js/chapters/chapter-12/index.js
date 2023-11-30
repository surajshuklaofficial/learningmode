// destructuring of arrays

let arr = [1, 2, 3, 4, 5];

// destructuring assignment
let [ i, j, k, l, m] = arr;
console.log(i, j, k, l, m);

// skipping assignments
let [x, , , , z] = arr;
console.log(x, z);

// destructuring assignment of nested arrays
let arr2 = [1, 2, 3, [1, 2, 3]];
[i, , , [j, k, l]] = arr2;
console.log(i, j, k, l);

let newMenu0 = 'rasmalain';
// destructuring of objects
let hotel = {
    name: 'hotel',
    Location: 'street No xyz Delhi',
    categories: ["chinese", "italian", "english"],
    mainMenu: ["FoodAssistant", "FoodB", "FoodC"],
    openingHours: {
        sunday:{open: "09:00AM", close: "11:00PM"},
        monday:{open: "10:00AM", close: "10:00PM"},
        tuesday:{open: "10:00AM", close: "10:00PM"}
    },

    // ES6 - new way of writing a method inside Object otherwise key: function(){}
    order(){
        console.log('order placed')
    },

    // dynamic key
    [newMenu0]: 'newMenu'

    // shorthand Object literal
}

console.log('hotel here', hotel)
// let { name, Location, mainMenu} = hotel;
// console.log(name, Location, mainMenu);

// customize variables name: 'key-matching: new-variable-name'; here variable created will be 'new-variable-name'
let { name:hotelName, Location:hotelLocation, mainMenu:Menu} = hotel;
console.log(hotelName, hotelLocation, Menu);

// setting default values
let { name, Menu:newMenu = [], categories=[]} = hotel;
console.log(name, newMenu, categories);

// destructuring nested objects
let { openingHours } = hotel;
console.log(openingHours);
let {monday} = openingHours;
let {sunday: {open, close }} = openingHours; /// sunday will not be defined here
console.log(monday, close, open);

// spread operator
let nums = [ 2, 3, 4, 5 ];
console.log(...nums, nums); // ... ellipsis operator; ...nums will be called array literal here

// join two arrays
// [ ...arr1, ...arr2, ...arr3]

// rest operator : opposite of spread -> here too ellipsis used
let [a, b, ...c] = nums;
let [x2, y2, ...rest] = nums;
console.log(a, b, c, x2, y2, rest);

let {sunday, ...weekDays} = hotel.openingHours;
console.log(sunday, weekDays);

// short circuiting

// falsy values : 0, null false, undefined, ''(empty string)

// and operator checks all if nothing is false then returns the last value
let result = true && true && 'coders'; 

// or operator checks and return immediately when it finds true value
let result2 = 'programmers' || false || false;
console.log(result, result2)

// nullish coalesing operator ?? - returns true value immediately when it finds it; it consider null and undefined as false values only
let result3 = 0 ?? 10;
console.log(result3)

// for-of loop
for (let item of hotel.categories) console.log(item);

for (let item of hotel.categories.entries()) console.log(item)

for (let [i, item] of hotel.categories.entries()) console.log(i, item)

// Optional Chaining (?.)
// return null or undefined if does not exist

// Object methods

// Object.keys(objectVar) -> returns array of keys as elements
// Object.values(objectVar) -> returns array of values as elements
// Object.entries(objectVar) -> returns array of [key, values] as elements


// set DS
let itemSet = new Set([1, 3, 4 , 4, 3, 4])
console.log(itemSet)
console.log(itemSet.size)
console.log(itemSet.has(3))
itemSet.add(9)
itemSet.delete(9)
// console.log(itemSet[0]) // not allowed; return undefined

// set are also iterables
for (let item of itemSet) console.log(item)

itemSet = new Set("programmers")
console.log(itemSet)

itemSet.clear()

// map in js - no restriction to key

let restaurent = new Map();

restaurent.set('name', "Bombary hotel");
restaurent.set(1, "Address1")
            .set(2, "Address2")
            .set(3, "Address3");
restaurent.set(true, "Address4");


// getting the value
console.log(restaurent.get(1));
console.log(restaurent.get('name'));
console.log(restaurent.get(true));

restaurent.has('name')

// length
console.log(restaurent.size)

//restaurent.clear()