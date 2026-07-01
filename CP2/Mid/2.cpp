/*

    Problem: In the kingdom of Vectronia, brave adventurers venture into ancient dragon caves in search of
    legendary treasure. These caves are filled with loot gems of various values. However, not all loot is
    worth collecting. The royal treasury wants only the top k highest-value gems, and your task is to help
    the adventurers make the most efficient decision.
    Each cave holds a list of gem values, and your job is to extract the k largest gem values and return
    them in descending order for appraisal at the palace.
    Input: The first line contains two integers n and k (1 ≤ k ≤ n ≤ 105) - the number of gems and the number of gems to collect.
    The second line contains n integers the value of each gem (-10" ≤ value ≤ 10°).
    Output: Print k integers the top k gem values in descending order.

        Sample Input 1"
            7 3
            5 -2 9 1 7 3 6

        Sample Input 2:
            5 2
            -1 -2 -3 -4 -5

    Sample Output 1:
            9 7 6

    Sample Output 2:
            -1 -2

    Topics: multiset, set, or priority queue for maintaining top k elements
    Explanation: Extract the top k largest gem values from n gems. Multiple approaches possible.

*/

//Solution 1: Using multiset (keeps sorted order)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    multiset<int, greater<int>> gems; // descending order
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        gems.insert(value);
    }
    
    auto it = gems.begin();
    for (int i = 0; i < k; i++) {
        cout << *it;
        if (i < k - 1) cout << " ";
        it++;
    }
    cout << endl;
    
    return 0;
}


/*
//Solution 2: Using priority queue
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    priority_queue<int> pq; // max heap
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        pq.push(value);
    }
    
    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(pq.top());
        pq.pop();
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}

*/