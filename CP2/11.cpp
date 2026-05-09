/*
    Problem Statement
    You are given a string S consisting of lowercase English letters.
    For every substring of S, define its score as follows:
    • If the substring is a palindrome, its score is equal to its length
    • Otherwise, its score is 0
    Your task is to compute the total score of all substrings of S.

    Input format
    S

    Output format
    Print a single integer — the total score of all substrings.
    Constraints
    • 1≤∣S∣≤2000
    • String contains only lowercase English letters

    Sample Input
    aba

    Sample Output
    6

    Explanation:
    All substrings of "aba":
    • "a" → palindrome → score = 1
    • "b" → palindrome → score = 1
    • "a" → palindrome → score = 1
    • "ab" → not palindrome → score = 0
    • "ba" → not palindrome → score = 0
    • "aba" → palindrome → score = 3
    Total score = 1+1+1+3=6
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    
    int n = s.length();
    long long totalScore = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                totalScore += (j - i + 1);
            }
        }
    }
    
    cout << totalScore << endl;
    
    return 0;
}