/*
    You are given a sequence of integers. After each insertion, you need to
    report the sum of the three largest elements seen so far.
    If fewer than 3 elements, print -1.

    Input:
    ● The first line contains a single integer N (1 ≤ N ≤ 2×10^5)
    ● The second line contains N integers A1,A2,...,A(N) (1 ≤ Ai ≤ 2×10^5)

    Output:
    Print N integers. For each index i:
    ● If i < 3, print -1
    ● Otherwise, print the sum of the largest 3 elements.

    Sample 1:
    INPUT:
    7
    10 5 20 1 25 3 30

    OUTPUT:
    -1 -1 35 35 55 55 75
*/

//Solution 1: Using Multiset:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    multiset<int, greater<int>> top3; // descending order
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        top3.insert(x);
        
        if (i < 2) {
            cout << -1;
        } else {
            // Get top 3 elements
            auto it = top3.begin();
            long long sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += *it;
                it++;
            }
            cout << sum;
        }
        
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}

//Solution 2: Using Priority Queue (Min Heap of size 3)

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if (minHeap.size() < 3) {
            minHeap.push(x);
        } else {
            if (x > minHeap.top()) {
                minHeap.pop();
                minHeap.push(x);
            }
        }
        
        if (i < 2) {
            cout << -1;
        } else {
            // Sum all elements in heap (top 3)
            priority_queue<int, vector<int>, greater<int>> temp = minHeap;
            long long sum = 0;
            while (!temp.empty()) {
                sum += temp.top();
                temp.pop();
            }
            cout << sum;
        }
        
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
*/
