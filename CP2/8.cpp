/*
    You are given a string S of length N, consisting of lowercase English letters, and
    an integer K.
    In one operation, you can either:
    ● add any character in the string, or
    ● remove any character from the string.
    Your task is to determine the minimum number of operations required to
    transform the string such that every character that appears in the string
    appears exactly K times.
    Constraints:
    ● 1 ≤ N ≤ 2 × 10⁵
    ● 1 ≤ K ≤ 2 × 10⁵
    ● S contains only lowercase letters ('a'–'z')
    Sample 1:
    INPUT:
    7 3
    aabbbcc

    OUTPUT:
    2

    NOTE: you have to add 1 ‘a’ and 1 ‘c’ so that every character appears exactly 3
    times.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    map<char, int> freq;
    
    for (char c : s) {
        freq[c]++;
    }
    
    int operations = 0;
    
    for (auto& p : freq) {
        int count = p.second;
        
        if (count % k == 0) {
            // Already multiple of k, no operation needed
            continue;
        } else {
            // Calculate minimum operations
            int remainder = count % k;
            int toAdd = k - remainder;
            int toRemove = remainder;
            
            operations += min(toAdd, toRemove);
        }
    }
    
    cout << operations << endl;
    
    return 0;
}

