/*
    1. The Favorite Spellbook (STL Map)Problem:
    Find the most borrowed book title. If there’s a tie in frequency, choose the title with the longest length.
    Logic: Use a std::map<string, int> to store the frequency of each title. Iterate through the map to find the maximum frequency, applying the length tie-breaker.
    Answer (Sample): 
    Input: firestorm, shadowbind, firestorm, frostlight, shadowbind, firestorm, shadowbind.  
        Frequencies: firestorm: 3, shadowbind: 3, frostlight: 1.
        Tie-breaker: Both firestorm and shadowbind have 3 borrows. shadowbind (10 chars) is longer than firestorm (9 chars).
        => Result: shadowbind

    Topics: map for frequency counting
    Explanation: Track how many times each book is borrowed using a map, then find the one with the highest frequency (and break ties by largest length).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<string, int> bookCount;
    
    for (int i = 0; i < n; i++) {
        string book;
        cin >> book;
        bookCount[book]++;
    }
    
    string result;
    int maxCount = 0;
    
    for (auto& p : bookCount) {
        if (p.second > maxCount || 
            (p.second == maxCount && p.first.length() > result.length())) {
            maxCount = p.second;
            result = p.first;
        }
    }
    
    cout << result << endl;
    
    return 0;
}