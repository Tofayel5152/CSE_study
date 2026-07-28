#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2; // for large numbers use start + (end - start)/2

        if (arr[mid] == target) {
            return mid; // Target found
        }
        else if (arr[mid] < target) {
            start = mid + 1; // Search in the right half
        }
        else {
            end = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements (sorted order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target element to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}