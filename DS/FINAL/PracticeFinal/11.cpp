/*Q2. In one of the puzzle tasks, players receive a nearly sorted list of clue numbers that must be arranged perfectly.
Since the list is already close to sorted, they prefer a method that finishes quickly with minimal adjustments.
They need an algorithm efficient for small or nearly sorted datasets. Which algorithm should they use? Write code for this algorithm in C++.*/
#include <bits/stdc++.h>
using namespace std;

void insertionSortForNearlySorted(vector<int> &arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Shift elements that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // Explanation: Insertion Sort is best for nearly sorted data
    // because it has O(n) time complexity when data is nearly sorted
    // and requires minimal adjustments
    
    int n;
    cout << "Enter number of clue numbers: ";
    cin >> n;
    
    vector<int> clues(n);
    cout << "Enter nearly sorted clue numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> clues[i];
    }
    
    insertionSortForNearlySorted(clues);
    
    cout << "Perfectly arranged clues: ";
    for (int i = 0; i < n; i++) {
        cout << clues[i] << " ";
    }
    cout << endl;
    
    return 0;
}