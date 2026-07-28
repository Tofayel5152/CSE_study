#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string expr) {
    stack<char> st;

    // Traverse each character
    for (char ch : expr) {
        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            // Check if stack is empty
            if (st.empty()) {
                return false;
            }

            // Check if brackets match
            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // Stack should be empty at the end
    return st.empty();
}

// Driver code
int main() {
    cout << "=== Balanced Parentheses Checker ===" << endl << endl;

    string test1 = "()[]{}";
    string test2 = "([)]";

    cout << "Test 1: '" << test1 << "' --> "
         << (isBalanced(test1) ? "Balanced " : "Not Balanced") << endl;

    cout << "Test 2: '" << test2 << "'--> "
         << (isBalanced(test2) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}
