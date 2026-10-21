let cells = document.querySelectorAll(".cell");
let resetbtn = document.querySelector("#reset");
let newGamebtn = document.querySelector(".new-game");
let msgcontainer = document.querySelector(".msg-container");
let msg = document.querySelector(".msg");
/* In the game we need to keep track of the current player and the game state. Because 
we have two players, and we need to know whose turn it is and what symbol they are using (X or O).
We can use a variable to keep track of the current player using player0, and we can store our all winning 
patterns with an array so that we can check if a player has won the game. 
*/

let player0 = true; // true means player 0's turn, false means player 1's turn
let count = 0; // Count the number of moves made in the game

const winningPatterns = [
    [0, 1, 2], // Top row
    [3, 4, 5], // Middle row
    [6, 7, 8], // Bottom row
    [0, 3, 6], // Left column
    [1, 4, 7], // Middle column
    [2, 5, 8], // Right column
    [0, 4, 8], // Diagonal from top-left to bottom-right
    [2, 4, 6]  // Diagonal from top-right to bottom-left
];

cells.forEach((cell) => {
    cell.addEventListener("click", () => {
        count++; // Increment the move count
        if(player0) {
            cell.innerText = "0";
            player0 = false;
        } else {
            cell.innerText = "X";
            player0 = true;
        }
        cell.disabled = true; // Disable the cell after a move is made

        let isWinner = checkWinner(); // Check if there's a winner after each move

        if(count === 9 && !isWinner) { // Check if all cells are filled and no winner
                gameDraw(); // Call the gameDraw function if all cells are filled and no winner
            }  
    });
});

const resetGame = () => {
    player0 = true; // Reset to player 0's turn
    count = 0; // Reset the move count
    enableAllCells(); // Enable all cells for a new game
    msgcontainer.classList.add("hide"); // Hide the message container
};

const disableAllCells = () => {
    for (let cell of cells) {
        cell.disabled = true; // Disable all cells to prevent further moves after a win
    }
};

const enableAllCells = () => {
    for (let cell of cells) {
        cell.disabled = false; // Enable all cells to allow moves for a new game
        cell.innerText = ""; // Clear the cell's text for a new game
    }
};

const showWinner = (winner) => {
    msg.innerText = `Congratulations! Player ${winner} wins!`;
    msgcontainer.classList.remove("hide"); // Remove the "hide" class to show the message container
    disableAllCells(); // Disable all cells to prevent further moves after a win
};

const gameDraw = () => {
    msg.innerText = "It's a draw!";
    msgcontainer.classList.remove("hide"); // Remove the "hide" class to show the message container
    disableAllCells(); // Disable all cells to prevent further moves after a draw
};

const checkWinner = () => {
    for (let pattern of winningPatterns) {

        let pos1Value = cells[pattern[0]].innerText;
        let pos2Value = cells[pattern[1]].innerText;
        let pos3Value = cells[pattern[2]].innerText;

        if(pos1Value !== "" && pos2Value !== "" && pos3Value !== "" ) {
            if(pos1Value === pos2Value && pos2Value === pos3Value) {
                showWinner(pos1Value); // Show the winner message
                return true; // Return true if a win is detected
            }
    } 
    return false; // Return false if no win is detected
    }
};

resetbtn.addEventListener("click", resetGame);
newGamebtn.addEventListener("click", resetGame);
