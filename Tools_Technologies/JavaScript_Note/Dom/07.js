/*
    * Attributes: Additional info of a tag/node
    node.getAttribute("attr") //to get the attribute value
    node.setAttribute("attr"," value") //to set the attribute val    

    * Style: Access style in js
    node.style

    * Insert Elements: adding new elements 
    Is a 2 step process: 
    * 1. create:
    let el = document.createElement("div“);
    * 2. Add:
    node.append( el ) //adds at the end of node (inside)
    node.prepend( el ) //adds at the start of node (inside)
    node.before( el ) //adds before the node (outside)
    node.after( el ) //adds after the node (outside)
    * or Delete:
    node.remove() //removes the node

    Lern more about:
    appandChild, removeChild.

*/

// let div = document.querySelector("div");
// console.log(div);

// let id = div.getAttribute("id");
// console.log(id);

// console.log(div.getAttribute("name"));

// div.setAttribute("name", "myNewRole");

// console.log(div.style);

// // diff. in name : in css background-color but in js backgroundColor (camelcase)
// div.style.backgroundColor = "pink";
// div.style.fontSize = "30px";
// // div.style.visibility = "hidden"; 

// // 1.
// let newButton = document.createElement("button");
// newButton.innerText = "Click Me!";

// // 2.
// // let div = document.querySelector("div"); // for adding append of div need to access div
// // (previously accessed thats why comment out)
// div.append(newButton);

// Q: Create a new button element. Give it a text of "Click Me!", background color of red and text color of white. 
// Insert it as the first element inside body.

// let newBtn = document.createElement("button");
// newBtn.innerText = "Click Me!";

// newBtn.style.color = "white";
// newBtn.style.backgroundColor = "red";

// document.querySelector("body").prepend(newBtn);

// Q: 1.Create a <p> tag in html, give it a class & 2.some styling. 3.Now create a new class in CSS and try to append 
// this class to the <p> element. Did you notice, how you overwrite the class name when you add a new one? Solve 
// this problem using classList.
// go to 07.html and 07.css then come here.

let paragraph = document.querySelector("P");
// paragraph.setAttribute("class", "newP"); //overwrites the class 
paragraph.classList.add("newP"); //adds the new class without overwriting the previous class
 // read more about classList.




