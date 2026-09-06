/*
    -> Operators: are used to perform operations on variables and values. In JS we have 4 types 
    of operators:
    1. Arithmetic Operators: are used to perform arithmetic operations on numbers. 
    Example: +, -, *, /, %, ++, --
    2. Assignment Operators: are used to assign values to variables. 
    Example: =, +=, -=, *=, /=, %=
    3. Comparison Operators: are used to compare two values and return a boolean value. 
    Example: ==, ===, !=, !==, >, <, >=, <=
    4. Logical Operators: are used to combine multiple boolean expressions and return a boolean value.
    Example: &&, ||, !

    * The difference between == and === is that == compares only the value of the variables 
    where as === compares both the value and the type of the variables.

    * There is a Operator called exponentiation operator (**) which is used to raise the 
    first operand to the power of the second operand.

    -> Conditional Statements: are used to perform different actions based on different conditions.
    There are 3 types of conditional statements in JS:
    1. if statement: It is used to execute a block of code if a specified condition is true.
    Example: if (condition) { // block of code } 
    2. if...else statement: It is used to execute a block of code if a specified condition is true,
    and another block of code if the condition is false. Example: if (condition) { // block of code } else { // block of code }
    3. else if statement: It is used to execute a block of code if a specified condition is true,
    and another block of code if the condition is false, and another block of code if the condition is false.
    Example: if (condition) { // block of code } else if (condition) { // block of code } else { // block of code }

    * We can also use nested if statements to check multiple conditions. 
    Example: if (condition) { // block of code } else { if (condition) { // block of code } else { // block of code } }

    * We can aslo use Ternary operator to check a condition and return a value or string based on the condition.
    Example: condition ? value1 : value2; // if condition is true return value1 else return value2

    * We can also use switch statement to check multiple conditions. It is used to perform different actions based on different conditions.
    Example: switch (expression) { case value1: // block of code break; case value2: // block of code break; default: // block of code }
*/

// let a = 5;
// let b = 10;

// console.log("a = ", a," and b = ", b); // a = 5 and b = 10
// console.log("a + b = ", a + b); // 15
// console.log("a - b = ", a - b); // -5
// console.log("a × b = ", a * b); // 50
// console.log("a ÷ b = ", a / b); // 0.5
// console.log("a % b = ", a % b); // 5
// console.log("a^b = ", a ** b); // 100000

// console.log("Is number 5 and string '5' are equal? ", 5 == '5'); // true 
// What it does is it converts the string '5' to number 5 and then compares them. 
// this is called type coercion. But if we want to get the exact comparison we can use
// the === operator which compares both value and type.

// console.log("Is the number 5 and string '5' equal? ", 5 === '5'); // false

// Same for != and !== operators. The != operator compares only the value of the variables 
// where as !== compares both the value and the type of the variables.


// Practice: Get user to input a number using prompt("Enter a number:"). Check if the number is a multiple of 5 or not.

// * Alert and Prompt: are not supported in Node.js environment. They are supported in browser environment. But what it does is it shows a 
// pop-up window or message box to the user. These two are same but the difference is that alert() is used to show a message to the user 
// and prompt() is used to show a message to the user and get input from the user. The input is stored in a variable. Example: let num = prompt("Enter a number:");

let num = prompt("Enter a number: ");

if (num % 5 === 0){
    console.log("Multiple of 5.");
}
else{
    console.log("Not multiple of 5.");
}


