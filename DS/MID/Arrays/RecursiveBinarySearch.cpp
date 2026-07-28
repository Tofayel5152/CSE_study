#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int target, int start, int end){

    if (start <= end){
        int mid = start + (end - start) / 2; // to avoid overflow

        if (arr[mid] > target){
            return binarySearch(arr, target, start, mid - 1);
        }
        else if (arr[mid] < target){
            return binarySearch(arr, target, mid + 1, end);
        }
        else{
            return mid; // Target found
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

    int result = binarySearch(arr, target, 0, n - 1);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}