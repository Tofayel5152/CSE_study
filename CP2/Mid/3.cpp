/*
    You are given N numbers, where you have find the maximum distinct numbers from that N numbers
    Input:
        Each test case contains two lines:
        ● The first line consists a number N (2 ≤ N ≤ 100000) number of elements.
        ● The second line contains N numbers ( 11 ≤ Bj ≤ 1018).
    Output:
        Print the total distinct numbers.
    Sample Input
            5
            10 10 10 5 6
    Sample Output
            3
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<long long> distinct;
    
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        distinct.insert(num);
    }
    
    cout << distinct.size() << endl;
    
    return 0;
}