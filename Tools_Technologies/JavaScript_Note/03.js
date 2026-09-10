/*
    Loops: are used to repeat a block of code until a specified condition is met.
    There are three main types of loops in JavaScript: for, while, and do...while.

    * For Syntax:
    for (initialization; condition; increment/decrement) {
        // block of code to be executed
    }

    * for example:
    for (let i = 0; i < 5; i++) {
        console.log(i);
    }

    * While Syntax:
    initialization;
    while (condition) {
        // block of code to be executed
        increment/decrement;
    }

    * while example:
    let i = 0;
    while (i < 5) {
        console.log(i);
        i++;
    }

    * Do...While Syntax:
    initialization;
    do {
        // block of code to be executed
        increment/decrement;
    } while (condition);

    * do...while example:
    let i = 0;
    do {
        console.log(i);
        i++;
    } while (i < 5);

    Two more special types of loops are: for...in and for...of loops. The for...in loop 
    is used to iterate over the properties of an object, while the for...of loop is used 
    to iterate over the values of an iterable object.

    * For...of Syntax:
    for (variable of iterable object) {
        // block of code to be executed
    }
    
    * for...of example:
    const arr = [10, 20, 30, 40, 50];
    for (const value of arr) {
        console.log(value);
    }
    
    * For...in Syntax:
    for (keys in object) {
        // block of code to be executed
    }

    * for...in example:
    const obj = {a: 1, b: 2, c: 3};
    for (const key in obj) {
        console.log(key, obj[key]);
    }

    * Difference between for...in and for...of loops is that for...of loop is used to iterate over 
    the values of an iterable string or array, whereas for...in loop is used to iterate over the 
    properties of an object.
*/

// Practice: Print all the even numbers from 1 to 100.

    // for (let i = 1; i <= 100; i++) {
    //     if (i % 2 === 0) {
    //         console.log(i);
    //     }
    // }



/*
    Strings: are used to represent text in JavaScript. Strings can be created using single quotes, 
    double quotes, or backticks.
    Example:
    const str1 = 'Hello';
    const str2 = "World";
    const str3 = `Hello World`; (Used for template literals. Template literals is a way to create 
    strings that can contain variables and expressions. For example: let obj = {name: "John", age: 30};
    let output = `My name is ${obj.name} and I am ${obj.age} years old.`; console.log(output); 
    // Output: My name is John and I am 30 years old.

    * ${} -> substitution operator. To create strings by doing substitution placeholder is called String Interpolation.
    * Escape characters: special characters that are used to represent certain characters in a string which 
    * does some special work ( not printed out also not counted 2 ( \n ) but 1 in string length). 
    Example: const str = "Hello\nWorld"; console.log(str); 
    // Output: Hello
    //         World ( \n is an escape character that represents a new line. )
    
    Whereas, the normal string concatenation would be: let obj = {name: "John", age: 30};
    let output = "My name is " + obj.name + " and I am " + obj.age + " years old."; console.log(output); 
    // Output: My name is John and I am 30 years old.
    
    Every string in JS has some built-in properties and methods(functions) that can be used to manipulate 
    the string. String somewhat acts like an object. 
    Some of the commonly used string methods are:
    * length: returns the length of the string. 
    Ex: const str = "Hello"; console.log(str.length); // Output: 5
    * toUpperCase(): converts the string to uppercase. 
    Ex: const str = "Hello"; console.log(str.toUpperCase()); // Output: HELLO
    * toLowerCase(): converts the string to lowercase. 
    Ex: const str = "Hello"; console.log(str.toLowerCase()); // Output: hello
    * indexOf(): returns the index of the first occurrence of a specified value in a string. 
    Ex: const str = "Hello"; console.log(str.indexOf("e")); // Output: 1
    * replace(): replaces a specified value with another value in a string. 
    Ex: const str = "Hello"; console.log(str.replace("H", "J")); // Output: Jello
    Here, if our target value is multiple times in the string then it will only replace the first 
    occurrence of the target value.
    * replaceAll(): replaces all occurrences of a specified value with another value in a string.
    Ex: const str = "Hello Hello"; console.log(str.replaceAll("Hello", "Hi")); // Output: Hi Hi
    
    * split(): splits a string into an array of substrings. 
    Ex: const str = "Hello World"; console.log(str.split(" ")); // Output: ["Hello", "World"]
    * substring(): returns a part of the string between two specified indices. 
    Ex: const str = "Hello World"; console.log(str.substring(0, 5)); // Output: Hello
    * trim(): removes whitespace from both ends of a string.
    Ex: const str = "   Hello World   "; console.log(str.trim()); // Output: Hello World
    * slice(): returns a part of the string between two specified indices.
    Ex: const str = "Hello World"; console.log(str.slice(0, 5)); // Output: Hello
    Here,console.log(str.slice(0) ending index is not mandatory, if we don't provide ending index then 
    it will take the string length as ending index.
    and if we provide nothing it will return the whole string. Ex: console.log(str.slice()); 
    // Output: Hello World (not ideal to use)
    * concat(): concatenates two or more strings.
    Ex: const str1 = "Hello"; const str2 = "World"; console.log(str1.concat(" ", str2)); // Output: Hello World
    We can also use the + operator to concatenate strings. Ex: const str1 = "Hello"; const str2 = "World"; console.log(str1 + " " + str2); 
    // Output: Hello World
    * charAt(): returns the character at a specified index in a string.
    Ex: const str = "Hello"; console.log(str.charAt(1)); // Output: e

    * The changes made by the string methods are not permanent. The original string remains unchanged. We can assign the result 
    of the string method to a new variable to store the modified string. Because in JS strings are immutable(means Which doesn't changes).

    * We can also use iteration to get each character of a string. For example: const str = "Hello"; 
        for (let i = 0; i < str.length; i++) { console.log(str[i] + " "); } // Output: H e l l o
    
*/

// Practice: Prompt the user to enter their full name. Generate a username for them based on the input. Start username with @, followed by 
// their full name and ending with the fullname length.

let fullName = prompt("Enter your full name: ");
let username = "@" + fullName.toLowerCase().replaceAll(" ", "") + fullName.length;
console.log("Username: ", username);
    