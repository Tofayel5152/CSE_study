/*
    You are given a bracket sequence consisting only of characters '(' and ')'.
    A sequence of brackets is called balanced if one can turn it into a valid math expression. For
    example, sequences "(())()", "()", and "(()(()))" are
    balanced, while ")(", "(()", and "(()))(" are not.
    Input:
    A single string S (1 ≤ |S| ≤ 2 × 10⁵), consisting only of characters '(' and ')'.
    Output:
    Print "YES" if the string is balanced, otherwise print "NO".
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    stack<char> st;
    
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else { // c == ')'
            if (st.empty()) {
                cout << "NO" << endl;
                return 0;
            }
            st.pop();
        }
    }
    
    if (st.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}