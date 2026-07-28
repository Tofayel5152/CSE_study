#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isOperand(char c) {
    return isalnum(c);
}

// -------------- INFIX TO POSTFIX ----------------
string infixToPostfix(string s) {
    stack<char> st;
    string res;

    for (char c : s) {
        if (isOperand(c)) {
            res += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop(); // pop '('
        }
        else {  // operator
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}


int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix: " << infixToPostfix(infix) << endl;

    return 0;
}
