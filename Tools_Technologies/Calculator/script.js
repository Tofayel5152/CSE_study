const display = document.getElementById('display');
const buttons = document.querySelectorAll('.btn');
let justCalculated = false;

buttons.forEach(button => {
  button.addEventListener('click', () => {
    const value = button.dataset.value;
    const isOperator = ['+', '-', '*', '/'].includes(value);

    if (value === 'clear') {
      display.value = '';
    } else if (value === 'del') {
      display.value = display.value.slice(0, -1);
    } else if (value === '=') {
      calculate();
    } else {
      if (justCalculated && !isOperator) {
        display.value = '';
      }
      display.value += value;
    }

    justCalculated = (value === '=');
  });
});

function calculate() {
  const expression = display.value.replace(/[+\-*/.]+$/, '');

  try {
    display.value = eval(expression);
  } catch {
    display.value = 'Error';
  }
}