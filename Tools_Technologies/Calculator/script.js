const display = document.getElementById('display');
const buttons = document.querySelectorAll('.btn');
let justCalculated = false;

function handleInput(value) {
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
}

buttons.forEach(button => {
  button.addEventListener('click', () => {
    handleInput(button.dataset.value);
  });
});

const keyMap = {
  'Enter': '=',
  '=': '=',
  'Backspace': 'del',
  'Escape': 'clear',
  'Delete': 'clear',
  '*': '*',
  'x': '*',
  'X': '*',
  '/': '/',
  '+': '+',
  '-': '-',
  '.': '.'
};

document.addEventListener('keydown', (e) => {
  let value;

  if (/^[0-9]$/.test(e.key)) {
    value = e.key;
  } else if (keyMap[e.key] !== undefined) {
    value = keyMap[e.key];
  } else {
    return;
  }

  e.preventDefault();
  handleInput(value);
});

function calculate() {
  const expression = display.value.replace(/[+\-*/.]+$/, '');

  try {
    display.value = customEval(expression);
  } catch {
    display.value = 'Error';
  }
}

function customEval(expression) {
  let operator = '';
  let operatorIndex = -1;
  for (let i = 0; i < expression.length; i++) {
    if (
      expression[i] === '+' ||
      expression[i] === '-' ||
      expression[i] === '*' ||
      expression[i] === '/'
    ) {
      operator = expression[i];
      operatorIndex = i;
      break;
    }
  }

  if (operatorIndex === -1) {
    return Number(expression);
  }

  const left = Number(expression.slice(0, operatorIndex));
  const right = Number(expression.slice(operatorIndex + 1));

  if (isNaN(left) || isNaN(right)) {
    throw new Error('Invalid expression');
  }

  if (operator === '+') {
    return left + right;
  } else if (operator === '-') {
    return left - right;
  } else if (operator === '*') {
    return left * right;
  } else if (operator === '/') {
    if (right === 0) {
      throw new Error('Cannot divide by zero');
    }

    return left / right;
  }

  throw new Error('Unknown operator');
}