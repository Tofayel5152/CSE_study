// /*
//     * DOM: Document Object Model : When a web page is loaded the browser creates a DOM of the page.
//     * Structure: (Every node/point is a object)
//     -> Window-> Document-> HTML--> head
//                                |-> body
    
//     We can access HTML through js, in doccument(way of accessing) which is a model of HTML code.(it's DOM)

//     * Use console.dir(part of window object) to print object. Ex: console.dir(window.document)
//     * Window Object: represents an open window in a browser. it is browser's object(not JS's) and is
//     sutomatically created by browser. It's a global object with lots of properties & methods. 

//     * What we can do with DOM and JS access(object): We can dynamically access and change HTML and css structure
//     and content. Its called DOM manipulation.

// */

// // Selecting with id:(id is unique, one id for one tag, represented #id)
// let heading = document.getElementById("heading");
// console.dir(heading);   // h1#heading

// // Selecting with class:(class is like id but not unique, represented .class)
// let headings = document.getElementsByClassName("heading");
// console.dir(headings);   // HTMLCollection(1) -> h3.heading

// // Selecting with tag
// let p = document.getElementsByTagName("p");
// console.dir(p); // HTMLCollection(1) -> p

// // We can use an upgraded version of accessing elements, using querySelector. It automatically detects types.
// let query = document.querySelector("p"); // 1st element occurrence
// console.dir(query); // p

// let queryAll = document.querySelectorAll("p"); // all element occurrence
// console.dir(queryAll);  // NodeList -> 0.p , 1.p

// // in query selector we need to write calss with a dot
// document.querySelector(".heading");
// // in query selector we need to write id with a hash
// document.querySelector("#heading");

// // We can get/change properties with:
//     // tagName: returns tag for element nodes
//     query.tagName;

//     // innerText: returns the text content of the element and all its children.
//     let body = document.querySelector("body");
//     body.innerText; // need to run in console to check
//     // we will also see \n between words which means next line(also next tag)

//     // innerHTML : returns the plain text or HTML contents in the element.
//     body.innerHTML; // need to run in console to check

//     //* We can also set values/text using properties.
//     body.innertext = "Abcdefg"; // need to run in console to check
//     // Changes all text in body.( deletes previous and adds new)
//     // body.innerText = "<div> inner div </div>"; // instantly changes.
//     // We can also change tages of text by innerHTML (normally used)

//     // textContent : returns textual content even for hidden elements(hidden by style)
//     // innerText dont show hidden elements ,there comes textContent
//     let div = document.querySelector("div");
//     console.log(div);
//     // div.innerText; // need to run in console to check (output: '' (nothing))
//     // div.textContent; // need to run in console to check (output: '\n       footer text\n    ')


// /*
//     * What is children?:
//     In hierarchical form of DOM tree/structure, every node who has some sub-nodes or has one or more nodes connected 
//     directly below it is parent node and the sub-nodes are child nodes.
//     let a structure:
//     body-> div--> img, h1, p, div
//               |-> script
//     in html form:
//     <body>
//         <div>
//             <img>
//             <h1>   </h1>
//             <p>    </p>
//             <div>

//             </div>
    
//         </div>

//         <script>     </script>

//     </body>

//     Here, body is a parent and div and script is her children. Also div and script are siblings.
//     -> div is the first child of body.(easily from html)
//     -> There is two properties of parent node in DOM, dirstChild and lastChild(here script is last child)
//     -> The children of div are descendant of body.

//     And, div is a parent and img, h1, p and div is her children. Also img, h1, p and div are siblings.


//     A DOM tree nodes type:
//     1. text nodes
//     2. comment nodes
//     3. element nodes

//     *   We use these children and nodes for navigation.

//     */

// // Check first child
// console.dir(document.body.firstChild); // text (need to ignore we will work with elements)

// // accessing children
// document.querySelector("body").children;  // need to run in console to check
// // HTMLCollection(6) [h1#heading, h3.heading, p, p, button, script, heading: h1#heading]


// Practice: 
// 1. to Append
let h2 = document.querySelector("h2"); // 1st access element

// 2nd change using property
h2.textContent = h2.textContent + " from Apna College students"; // concatenate


// 2. to Access them & add some unique text
// 1st access elements
let divs = document.querySelectorAll(".box");
// 2nd change using index address and properties
// divs[0].innerHTML = "New unique 01";
// divs[1].innerHTML = "New unique 02";
// divs[2].innerHTML = "New unique 03";
// We can level up our programming using loops
let index = 1;
for (div of divs) {
    div.innerText = `New unique ${index}`;
    index++;
}