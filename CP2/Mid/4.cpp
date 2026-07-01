/*
    Given an array arr of n integers, you are tasked with creating a prefix sum array p and then answering q queries. Each query asks for the sum of elements 
    in a subarray from index s to t (1-based index).

    Input:
    · The first line contains an integer n -- the size of the array.
    · The second line contains n integers separated by spaces, representing the array arr.
    · The third line contains an integer q - the number of queries () Maliodous Rate
    · The next q lines each contain two integers s and t- the range for the query ()

    Output:
    For each query, output a single integer representing the sum of the elements from index s to t.
    Constraints:
    · 1 ≤ n, q ≤ 10^5
    · -10^5 ≤ arr [i] ≤ 10^5
    · 1 ≤ s ≤ t ≤ n

    Sample Input 1

        5
        1 2 3 4 5
        3
        1 3
        2 4
        1 5

    Sample Output 1

        6
        9
        15
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> arr(n + 1);
    vector<long long> prefix(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int s, t;
        cin >> s >> t;
        
        long long sum = prefix[t] - prefix[s-1];
        cout << sum << endl;
    }
    
    return 0;
}