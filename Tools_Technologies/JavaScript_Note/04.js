/*
    Arrays: is a linear D.S. that is a collection of data that can hold multiple values of different data types. 
    In JavaScript, arrays are dynamic, meaning they can grow and shrink in size as needed. Arrays are zero-indexed, 
    meaning the first element is at index 0, the second element is at index 1, and so on.

    * Array is a special type of object that allows you to store multiple values in a single variable.
    * Array is mutable, meaning you can change the values of an array after it has been created.
    
    * We can iterate over an array using a for loop, for...of loop, or forEach() method. The for...of loop is most commonly used for array iteration.
    Example:
    const fruits = ['apple', 'banana', 'orange'];
    for (const fruit of fruits) {
        console.log(fruit);
    }

    * Array methods: JS provides a wide range of built-in methods for working with arrays. There are two types of array methods: mutator methods and accessor methods. 
    Mutator methods modify the original array, while accessor methods return a new array or value without modifying the original array.
    * push(): adds one or more elements to the end of an array and returns the new length of the array.
    example:
    const fruits = ['apple', 'banana'];
    fruits.push('orange');
    console.log(fruits); // ['apple', 'banana', 'orange']
    * pop(): removes the last element from an array and returns that element.
    example:
    const fruits = ['apple', 'banana', 'orange'];
    fruits.pop();
    console.log(fruits); // ['apple', 'banana']
    * toString(): converts an array to a string and returns the result.
    example:
    const fruits = ['apple', 'banana', 'orange'];
    console.log(fruits.toString()); // 'apple,banana,orange'
    * concat(): merges two or more arrays and returns a new array.
    example:
    const fruits1 = ['apple', 'banana'];
    const fruits2 = ['orange', 'grape'];
    const allFruits = fruits1.concat(fruits2);
    console.log(allFruits); // ['apple', 'banana', 'orange', 'grape']
    * unshift(): adds one or more elements to the beginning of an array and returns the new length of the array.
    example:
    const fruits = ['banana', 'orange'];
    fruits.unshift('apple');
    console.log(fruits); // ['apple', 'banana', 'orange']
    * shift(): removes the first element from an array and returns that element.
    example:
    const fruits = ['apple', 'banana', 'orange'];
    fruits.shift();
    console.log(fruits); // ['banana', 'orange']
    * slice(): returns a shallow copy of a portion of an array into a new array object selected from start to end (end not included) where start and end represent 
    the index of items in that array. The original array will not be modified.
    example:
    const fruits = ['apple', 'banana', 'orange', 'grape'];
    const slicedFruits = fruits.slice(1, 3);
    console.log(slicedFruits); // ['banana', 'orange']
    console.log(fruits); // ['apple', 'banana', 'orange', 'grape']
    * splice(): changes the contents of an array by removing or replacing existing elements and/or adding new elements in place. It modifies the original array.
    example:
    const fruits = ['apple', 'banana', 'orange', 'grape'];
    fruits.splice(1, 2, 'kiwi', 'mango');
    console.log(fruits); // ['apple', 'kiwi', 'mango', 'grape']
    const fruits = ['apple', 'banana', 'orange', 'grape'];
    fruits.splice(2); // works same as slice
    console.log(fruits); // ['apple','banana']
*/

// Practice: For a given array with marks of students -> [85, 97, 44, 37, 76, 60]. Find the average marks of the entire class.

let marks = [85, 97, 44, 37, 76, 60];
let sum = 0;
for (let mark of marks) {
    sum += mark;
}
let avg = sum / marks.length;
console.log(`The average marks of the entire class is: ${avg}`);

// Practice: For a given array with prices of 5 items -> [250, 645, 300, 900, 50]. All items have an offer of 10% OFF on them. Change 
// the array to store final price after applying offer.

let prices = [250, 645, 300, 900, 50];

let index = 0; // indiectly tracking the index of the array
for (let price of prices){
    let offer = price/10; // 10% of the price
    prices[index] = prices[index] - offer;
    console.log(`The final price of item ${index} is: ${prices[index]}`);
    index++;
}

for(let i = 0; i < prices.length; i++){// directly tracking the index of the array
    let offer = prices[i] / 10; // 10% of the price
    prices[i] -= offer;
}
console.log(prices);

// Practice: Qs. Create an array to store companies -> "Bloomberg", "Microsoft", "Uber", "Google", "IBM", "Netflix" 
// a. Remove the first company from the array, b. Remove Uber & Add Ola in its place, c. Add Amazon at the end

let companies = ["Bloomberg", "Microsoft", "Uber", "Google", "IBM", "Netflix"];

companies.shift(); // a no. =>["Microsoft", "Uber", "Google", "IBM", "Netflix"]
companies.splice(1,1, "Ola"); // b no. => ["Microsoft", "Ola", "Google", "IBM", "Netflix"]
companies.push("Amazon"); // c no. => ["Microsoft", "Uber", "Google", "IBM", "Netflix", "Amazon"]

console.log(companies);
