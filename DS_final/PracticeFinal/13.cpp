/*Q4. A company is building a mathematical expression evaluator for an online learning platform.
Before calculating the result of a student's input, the system must first verify that all parentheses, braces, and brackets in the expression are correctly paired and properly nested.
For instance, an expression like [(2+3)*{5-1}] is valid, but ([2+3]*5-1} is not. The system should use a stack to efficiently check for balanced brackets in any given expression,
write code for this in C++.*/
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string expression) {
    stack<char> s;
    
    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) return false;
            
            char top = s.top();
            s.pop();
            
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter mathematical expression: ";
    getline(cin, expression);
    
    if (isBalanced(expression)) {
        cout << "Expression has balanced brackets ✓\n";
    } else {
        cout << "Expression has unbalanced brackets ✗\n";
    }
    
    return 0;
}