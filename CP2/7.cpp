/*
    You are given an array A consisting of N integers.
    ➢ A subsequence of an array is a sequence that can be derived from the
    array by deleting zero or more elements without changing the order of
    the remaining elements.
    Your task is to:
    1. Determine the total number of non-empty subsequences of the
    array A.
    2. Output all such subsequences.
    Constraints:
    ● 1 ≤ N ≤ 20
    ● 1 ≤ Aᵢ ≤ 100

    Sample Input:
    3
    1 2 3

    Sample Output:
    7
    1
    1 2
    1 2 3
    1 3
    2
    2 3
    3
*/

// Using Recursion:

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

void generateSubseq(vector<int>& arr, int idx, vector<int>& current) {
    if (idx == arr.size()) {
        if (!current.empty()) {
            result.push_back(current);
        }
        return;
    }
    
    // Don't pick current element
    generateSubseq(arr, idx + 1, current);
    
    // Pick current element
    current.push_back(arr[idx]);
    generateSubseq(arr, idx + 1, current);
    current.pop_back(); // backtrack
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> current;
    generateSubseq(arr, 0, current);
    
    cout << result.size() << endl;
    
    for (auto& subseq : result) {
        for (int i = 0; i < subseq.size(); i++) {
            cout << subseq[i];
            if (i < subseq.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}

// Using Bit Manipulation:

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int total = (1 << n) - 1; // 2^n - 1 (excluding empty set)
    
    cout << total << endl;
    
    for (int mask = 1; mask <= total; mask++) {
        vector<int> subseq;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subseq.push_back(arr[i]);
            }
        }
        
        for (int i = 0; i < subseq.size(); i++) {
            cout << subseq[i];
            if (i < subseq.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
*/