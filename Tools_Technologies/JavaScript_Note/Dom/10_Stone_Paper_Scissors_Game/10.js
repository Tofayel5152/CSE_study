let userScore = 0;
let computerScore = 0;
const userScorePanel = document.querySelector("#player-score");
const computerScorePanel = document.querySelector("#computer-score");

const choices = document.querySelectorAll(".choice");
const msg = document.querySelector(".msg-container");

const compChoice = () => {
    //randomly select a choice for the computer
    const options = ["rock", "paper", "scissors"];
    const randomIndex = Math.floor(Math.random() * options.length); /* Generate a random index between 0 and 2, where Math.random() is a built-in 
    JavaScript function that returns a random number between 0 (inclusive) and 1 (exclusive). By multiplying it by the length of the options array
    (which is 3), we get a random number between 0 and 3 (exclusive). Then, we use Math.floor() to round down to the nearest whole number, resulting 
    in an index of either 0, 1, or 2.*/
    return options[randomIndex];
};

const showWinner = (winner, userChoice, computerChoice) => {
    if (winner) {
        userScore++;
        userScorePanel.innerText = userScore;
        msg.innerText = `You win! ${userChoice} beats ${computerChoice}`;
        msg.style.backgroundColor = "green";
    } else {
        computerScore++;
        computerScorePanel.innerText = computerScore;
        msg.innerText = `Computer wins! ${computerChoice} beats ${userChoice}`;
        msg.style.backgroundColor = "red";
    }
};

const playGame = (userChoice) => {
    // Implementing the game logic here
    const computerChoice = compChoice();

    if (userChoice === computerChoice) { // draw
        msg.innerText = `It's a draw! ${userChoice} and ${computerChoice} are the same.`;
        msg.style.backgroundColor = "#081b31";

    } else if ((userChoice === "rock" && computerChoice === "scissors") ||
               (userChoice === "paper" && computerChoice === "rock") ||
               (userChoice === "scissors" && computerChoice === "paper")) { // user wins
                    showWinner(true, userChoice, computerChoice);

    } else { // computer wins
            showWinner(false, userChoice, computerChoice);
    }
};

choices.forEach((choice )=> {
    choice.addEventListener("click", () => {
        const userChoice = choice.getAttribute("id");
        playGame(userChoice);
    });
});