#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedLists(vector<int> &list1, vector<int> &list2) {
    vector<int> result;
    int i = 0, j = 0;
    
    while (i < list1.size() && j < list2.size()) {
        if (list1[i] <= list2[j]) {
            result.push_back(list1[i]);
            i++;
        } else {
            result.push_back(list2[j]);
            j++;
        }
    }
    
    while (i < list1.size()) {
        result.push_back(list1[i]);
        i++;
    }
    
    while (j < list2.size()) {
        result.push_back(list2[j]);
        j++;
    }
    
    return result;
}

int main() {
    int n1, n2;
    
    cout << "Enter size of first list: ";
    cin >> n1;
    vector<int> list1(n1);
    cout << "Enter elements of first sorted list: ";
    for (int i = 0; i < n1; i++) {
        cin >> list1[i];
    }
    
    cout << "Enter size of second list: ";
    cin >> n2;
    vector<int> list2(n2);
    cout << "Enter elements of second sorted list: ";
    for (int i = 0; i < n2; i++) {
        cin >> list2[i];
    }
    
    vector<int> merged = mergeSortedLists(list1, list2);
    
    cout << "Merged sorted list: ";
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}