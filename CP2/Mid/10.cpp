/*
    Problem Statement
    A piece of land is divided into N consecutive vertical strips, where the height of the iii-th
    strip is given by an integer array H.

    You are given Q queries. Each query consists of three integers L, R, X.
    For each query, consider all triplets (i,j,k) such that:
    • L≤i<j<k≤R
    A triplet is considered valid if:
    1. The three heights form a valid triangle
    2. The total height does not exceed X

    Formally, a triplet (a,b,c) is valid if:
    a+b>c and a+b+c≤X

    Your task is to determine the number of valid triplets for each query.
    Input formats:
    N Q
    H1 H2 H3 ... HN
    L1 R1 X1
    L2 R2 X2
    ...
    LQ RQ XQ

    Output formats:
    For each query, print a single integer — the number of valid triplets.

    Constraints
    • 1≤N≤2000
    • 1≤Q≤100
    • 1≤H[i]≤1000
    • 1≤L<R≤N
    • 1≤X≤3000

    Sample Input:
    5 1
    2 3 4 5 6
    1 5 12

    Sample Output:
    5

*/
#include <bits/stdc++.h>
using namespace std;

bool isValidTriangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        
        int count = 0;
        
        for (int i = l; i <= r; i++) {
            for (int j = i + 1; j <= r; j++) {
                for (int k = j + 1; k <= r; k++) {
                    int a = h[i], b = h[j], c = h[k];
                    
                    if (isValidTriangle(a, b, c) && a + b + c <= x) {
                        count++;
                    }
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}