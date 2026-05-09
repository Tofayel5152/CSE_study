/*
    In the realm of Eldoria, each mage maintains a log of their mana levels during a long quest. The levels
    fluctuate due to battles and resting. You are given an array where each element represents the mana level
    at a specifie point in time
    Your task is to find the maximum difference between two mana levels where the larger value comes
    after the smaller one. If the mana level only decreases or stays the same, return 0.

    Input Format:
    The first line contains an integer n (2 ≤ n ≤ 105), the number of mana recordings.
    The second line contains n space-separated integers, each representing the mana level at a point in
    time

    Output Format:
    Print a single integer - the maximum difference between any two mana levels where the higher
    value appears after the lower value. If no such pair exists, print 0.

Constraints:

.

Sample Input 1:

6

3 1 4 8 7 2

Sample Output 1:

7

Explanation:
The maximum difference is 8 - 1 = 7. 1 comes
before 8, satisfying the condition.

Sample Input 2:
5

9 8 7 6 5

Sample Output 2:

0

Explanation:
All mana levels are decreasing, so no valid pair
exists where the higher value comes after the
lower one.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> mana(n);
    for (int i = 0; i < n; i++) {
        cin >> mana[i];
    }
    
    int maxDiff = 0;
    int minSoFar = mana[0];
    
    for (int i = 1; i < n; i++) {
        if (mana[i] > minSoFar) {
            maxDiff = max(maxDiff, mana[i] - minSoFar);
        }
        minSoFar = min(minSoFar, mana[i]);
    }
    
    cout << maxDiff << endl;
    
    return 0;
}