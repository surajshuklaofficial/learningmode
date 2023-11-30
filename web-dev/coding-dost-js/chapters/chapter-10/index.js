// Object Oriented Programming

// Constructor function and the new operator

// we can't use 'arrow' function as constructor

// call constructor function using 'new' keyword

// function automatically return {object}

// constructor function
let Car = function (color, model) {
    // instance properties
    this.color = color;
    this.model = model;
  
    // // Not a good practice - function inside function
    // this.login = function() {
    //     console.log('login method');
  
    // }
  };
  
  let instance1 = new Car("blue", 2000);
  let instance2 = new Car("red", 2000);
  
  console.log(instance1 instanceof Car);
  console.log(instance1, instance2);
  console.log(instance1);
  
  // prototype and protypical inheritance
  
  // Each Object created by the constructor function have and accesss
  // to all methods defined inside constructor prototype
  
  console.log("Car prototype", Car.prototype);
  
  // creating a method into prototype of Car
  Car.prototype.login = function () {
    console.log("login method");
  };
  
  console.log(instance1.__proto__); // return prototype same as of Car.prototype
  instance1.login();
  
  // we can also set Properties to prototype
  Car.prototype.company = "Honda"; // these properties are present to all instance of that class; these properties are present while printing instance but can accessed
  console.log(instance1.company);
  
  console.log(instance1.__proto__.isPrototypeOf(instance1)) // return true
  console.log(Car.prototype.isPrototypeOf(Car)); // return false becuase Car is made of prototype of Car constructor rather instance1 is made of
  console.log(Car.prototype.isPrototypeOf(instance1)) // return true
  // Car.prototype is prototype of all objects created through the car constructor
  
  
  // array
  let arr = [1, 3, 5, 6]; // [] is same as new Array([]);
  
  // chaining of prototype
  console.log(arr.__proto__) // prototype of array constructor
  console.log(arr.__proto__.__proto__) // prototype of object constructor
  console.log(arr.__proto__.__proto__.__proto__) // null
  console.log(Object.prototype)
  
  // ------------- traditional JS ends ------------
  
  class Car2 {
      constructor(color, model) {
          this.color = color;
          this.model = model;
      }
      startEngine() {
          console.log("This is start engine method of Car class");
      }
  
      get _startEngine() {
          console.log("This is another start engine method of Car class");
      }
  
      get description() {
          return `Color of bike is ${this.color} and it's model is ${this.model}`;
      }
  
      set changeColor(color){
          console.log(this.color = color);
      }
  }
  
  // // this is also possible
  // Car2.prototype.break = function() {
  //     console.log("This is break method of Car class");
  // }
  
  let honda = new Car2("black", 2023);
  console.log('honda prototype', honda.__proto__)
  console.log(honda)
  
  // setters and getters - accessors
  // setter
  honda.changeColor = 'Yellow';
  
  // getter - usually returns a value
  honda._startEngine
  honda.startEngine()
  console.log(honda.description)
  
  // static method - for Classes itself; not for instances; not inherited for all objects
  Car.breakMethod = function(){
      console.log("This is static method for Car");
  }
  
  Car.breakMethod()
  // some other examples
  // JSON.parse()
  // Array.from()
  
  // ------- inheritance ----------
  
  // child class
  class Bike extends Car2 {
  
  }
  
  let newBike = new Bike("black", 34);
  console.log(newBike)
  
  // one more child class
  class Bike2 extends Car2 {
      constructor(color, model, engineCapacity) {
          super(color, model); // constructor of parent class
          this.engineCapacity = engineCapacity;
      }
  
      bikeMethod() {
          console.log("This is bike method");
      }
  }
  
  let newbike2 = new Bike2("red", 43, "123CC")
  console.log("newbike2", newbike2)
  
  // inheritance using prototype method
  let Bike3 = function(color, model, engineCapacity){
      Car.call(this, color, model)
      this.engineCapacity = engineCapacity;
  }
  
  Bike3.prototype = Object.create(Car.prototype) // creates an Object of prototype equal to car prototype
  let bike3 = new Bike3("red", 43, '123CC');
  console.log(bike3)
  
  // Properties of classes 
  // classes aren't hoisted
  // classes are also first class citizens (Pass as an argument or can be return)
  // Classes are executed in strict mode
  
  // for chaining of methods we can return this in the preceding method