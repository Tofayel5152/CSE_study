/*
    Functions: a block of code that performs a specific task. Called or invoked whenever needed.
    * Function definition:
    function functionName(){
        // Do some work
    }
    or, 
    * (input/ parameter dependent:)
    function functionName(parameter1, parameter2,.....){
        // do some work using parameters
    }

    * Function Call:
    functionName();

    * Arrow Functions: Compact way of writing a function

    const functionName = (param1, param2 ... ) => {
        //do some work
    }
    
    here, const functionName is basically storing data, the main funvtion is after the equal sign. 
    But the functionName works like normal functions.
*/

// Practice: Create a function using the "function" keyword that takes a String as an argument & returns the number of vowels in the string.

function vowelCheck(s) {
  let count = 0;
  for (let i = 0; i < s.length; i++) {
    if (
      s[i].toLowerCase() === "a" ||
      s[i].toLowerCase() === "e" ||
      s[i].toLowerCase() === "i" ||
      s[i].toLowerCase() === "o" ||
      s[i].toLowerCase() === "u"
    ) {
      count++;
    }
  }
  return count;
}

console.log("Vowel Count: ", vowelCheck("Tofayel Ahmmed"));

// Practice: Create an arrow function to perform the same task.

const VowelCheck = (s) => {
  let count = 0;
  for (let i = 0; i < s.length; i++) {
    if (
      s[i].toLowerCase() === "a" ||
      s[i].toLowerCase() === "e" ||
      s[i].toLowerCase() === "i" ||
      s[i].toLowerCase() === "o" ||
      s[i].toLowerCase() === "u"
    ) {
      count++;
    }
  }
  return count;
};
console.log("Vowel Count: ", VowelCheck("Tofayel Ahmmed"));

/*
  * For Each Loop: arr.forEach( callBackFunction ) => a method only used in array.
  * For Each method is also known as Higher order Function/Method. A function which uses a function as a
  * parameter or returns a function is known as HOF.
  We can use functions as a parameter of another function in JS, its called callBackFunction.


  * Function vs method:
    The core difference between a function and a methodis their association(method) with an object or a class. 
    As associated, method is object dependent. Wtitten with a (.) dot operator like object.calculate().

  * CallBackFunction : Here, it is a function to execute "for each element" in the array
  * A callback is a function passed as an argument to another function.
  * We can use 3 parameters in a callBackFunction value or item, index or position, array.(We can use any name but
  * the meaning should be these 3)
  Example:
  arr.forEach( (val) =>{
      console.log(val);
    }
  )

  * Or,
  let num =[1,2,3,4,5];

  num.forEach(display);

  function display(element){
    console.log(element);
  }
*/

// Practice: For a given array of numbers, print the square of each value using the forEach loop.

let num =[1,2,3,4,5];

  num.forEach(square);
  num.forEach(display);

  function square(element,index,array){
    array[index] = Math.pow(element,2);
  }
  function display(element){
    console.log(element);
  }

/*
  * Map: Creates a new array with the results of some operation. The value its callback returns are 
  used to form new array. => arr.map( callbackFnx( value, index, array ) )
  Example:
  let newArr = arr.map( ( val ) =>{
      return val * 2;
    }
  )

  * Filter: Creates a new array of elements that give true for a condition/filter.
  Example: (all even elements)
  let newArr = arr.filter( (val ) => {
      return val % 2 === O;
    }
  )

  * Reduce: Performs some operations & reduces the array to a single value. It returns that single value.
  Used for the function/ operations that gets multiple value as input and give a single output.
  Example:
  const array1 = [1, 2, 3, 4];

  // 0 + 1 + 2 + 3 + 4
  const initialValue = 0;
  const sumWithInitial = array1. reduce(
    (accumulator, currentValue) => accumulator + currentValue
    , initialValue // explecit return(no use of curly brace{} or i need to return)
  );

  console. log(sumWithInitial);
// Expected output: 10
*/

// Practice: We are given array of marks of students. Filter out of the marks of students that scored 90+.

let marks = [100,90,60,80,99,95,45,89];

const got90Plus = marks.filter((value) => {
    if(value > 90) return value;
  }
);

console.log("Got 90+: " + got90Plus);

// Practice: Take a number n as input from user. Create an array of numbers from 1 to n. Use the reduce method to 
// calculate sum of all numbers in the array. Use the reduce method to calculate product of all numbers in the array.

let n = prompt("Give me a number: ");
let arr = [];
for(let i = 1; i <= n;i++){
  arr.push(i);
}

const sum = arr.reduce((prev, curr) => {
    return prev + curr;
  }
);

const product = arr.reduce((prev, curr) => prev * curr);

console.log("Sum: " + sum);
console.log("Product: " + product);