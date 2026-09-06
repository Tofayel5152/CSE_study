/*
    -> JS is a programming language. We use it to give instruction to computer.

    -> console.log is like cout in c++ which log(print) a message or expression to the console.
        console.log("Hello World");
        console.log(5+5); // 10

    -> Variables: are containers for storing data values. In JS we use var, let and const to declare variables.
    But we dont need to declare the type of variable like in c++ or java we use int, float, string etc. In JS we
    can store any type of data in a variable.(Dynamically typed language)
    In js we have 3 types of variables:
    1. var: It is global scoped variable. It can be re-declared and updated. We usually avoid using var because it 
    can lead to unexpected behavior due to its global scope.
    2. let: It is block scoped variable. It can be updated but not re-declared.
    3. const: It is block scoped variable. It cannot be updated or re-declared.

    And we have 7 primitive types of data types in JS:
    1. Number: It is used to store numeric values. Example: 5, 10, 3.14
    2. String: It is used to store text values. Example: "Hello", 'World'
    3. Boolean: It is used to store true or false values. Example: true, false
    4. BigInt: It is used to store large integer values. Example: 9007199254740991n
    5. Symbol: It is used to store unique values. Example: Symbol('foo')
    6. Null: It is used to represent the absence of any value. Example: null
    7. Undefined: It is used to represent a variable that has been declared but has not been assigned a value. 
    Example: let x; console.log(x); // undefined

    * In JS we can add number and number like 5+5 = 10, we can add string and string like "Hello" + "World" = "HelloWorld", 
    but when we add number and string like 5 + "Hello" = "5Hello" it will convert number to string and concatenate them. 
    This is called type coercion

    We also have 1 non-primitive data type in JS:
    1. Object: It is used to store collections of data and more complex entities. Declared -> key: value. Example: {name: "John", age: 30}
    we can acces key value pair using dot notation or bracket notation. Example: console.log(obj.name); // John 
    or console.log(obj["name"]); // John

    * We can change value of const object keys but we cannot reassign the object itself like other variables. 
    Example: const obj = {name: "John", age: 30}; obj.name = "Doe"; // valid 
    but obj = {name: "Doe", age: 25}; // invalid

    We have 3 subtypes of object in JS:
    1. Array: It is used to store multiple values in a single variable. Example: [1, 2, 3, 4, 5]
    2. Function: It is used to store a block of code that can be executed when called. 
    Example: function myFunction() { console.log("Hello World"); }
    3. Date: It is used to store date and time values. Example: new Date()

    * The difference between null and undefined is that null is known value (assigned) where as undefined is unknown value (not assigned). 

*/

// Practice: Create a constant object named "product" with properties "name", "price", "offer", and "rating" and store values.

    const product = {
        name: "Ball Pen",
        rating: 4,
        price: 150,
        offer: 10
    };

    console.log(product);
    console.log(typeof product); // prints the type of variable

    // Practice: Create a object named "profile" to store some information.

    const profile = {
        username: "@Tofayel5152",
        isFollowing: true,
        followers: 10000,
        following: 50,
        bio: "Student at IIUC, Department of CSE.  Ex-student of Navy College Ctg & J.B. High School.  Religious View: Islam"
    };

    console.log(profile);
