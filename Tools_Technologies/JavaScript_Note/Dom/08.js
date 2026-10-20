// Events: User interactions with the web page. The change in the state of an object is known as an Event.
// Like, clicking a button, double-clicking, pressing a key, etc. are all events.
// Events are fired to notify code of "interesting changes" that may affect code execution.
// When we deal with these kind of interesting changes, we call them "Event Handling" or "Event Listening".
// In DOM every node can fire events of any type. The event is fired when the user interacts with the node in some way.
// Sometimes, the event is fired when the state of the node changes. For example, when bettry level of a device changes, the event is fired.
// Some of the common events are: Mouse events(click, double click etc.), Keyboard events(keypress, keyup, keydown etc.),
// Form events(submit, change etc.), Print events and many more. We can handle these events using JavaScript.

let btn = document.querySelector("#clickMe");

// btn.onclick = ()=> {
//     alert("Button clicked");
// }

// If there are multiple event handlers for the same event, then the last one will override the previous ones. Also if we used inline event 
// handlers and js event handlers, then the js event handler will override the inline event handler.

/* Event object: It is a special object that has details about the event. Like the type of event, the target node, the position of the mouse pointer, etc.
All event handlers have access to the Event Object's properties and methods.

    node.event = (e) => {
                        \\ handle here
    }
Ex: e.target, e.type, e.clientX, e.clientY etc. (mostly used e.target and e.type)
*/

/*  Event Listeners: We have seen that we can handle events using the js event handlers. But multiple event handlers for the same event will override the
    previous ones. So to avoid this, we can use Event Listeners. We can add multiple event listeners for the same event and they will not override each other.
    Event Listeners are a kind of event handler that watches for a specific event on a specific node and executes a callback function when that event occurs.
    The callback function is also known as the event handler function.
    We can add event listeners using: node.addEventListener(event, callback), node.removeEventListener(event, callback) 
    For remove we need to pass the same callback function with same memory location that we used to add the event listener.
    So to do that we can use a named function or a variable that stores the function. Like if we do this: btn.addEventListener("click", () => {alert("Button clicked");}), 
    and then we do this: btn.removeEventListener("click", () => {alert("Button clicked");}), it will not remove the event listener because the two functions are different 
    in memory location.
    */ 

    btn.addEventListener("click", () => {
        alert("Button clicked");}
    )
    btn.addEventListener("click", (e) => {
        alert("Button clicked handler 2");
        console.log(e.type);}
    )

    const handler3 = () => {
        alert("Button clicked handler 3");
    };

    btn.addEventListener("click", handler3);
    btn.removeEventListener("click", handler3); // This will remove the handler3 event listener from the button.

    /*  Q: Create a toggle button that changes the screen to dark-mode when clicked & light-mode when clicked again. (1st go to 08.html and add a button then 08.css to 
    style it, then add the js code below.)
    */

    let toggleBtn = document.querySelector("#mode");
    let cuurrentMode = "light";
    let body = document.querySelector("body");

    toggleBtn.addEventListener("click", () => {
        if(cuurrentMode === "light"){
            cuurrentMode = "dark";
             // body.style.backgroundColor = "black"; changes the background color of the body element to black. But we can also do this using classList.add() and classList.remove() methods.
            body.classList.add("dark"); // here dark and light are the classes defined in 08.css
            body.classList.remove("light");
        } else {
            cuurrentMode = "light";
            body.classList.add("light"); //If we use classList.add("light") then it will add the class "light" to the body element and then we need to remove the class "dark" from the body element.
            body.classList.remove("dark");
        }
    });