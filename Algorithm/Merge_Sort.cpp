#include <bits/stdc++.h>
#include "random_int_array_generator.h"
using namespace std;

const string STUDENT_NAME = "Tofayel Ahmmed";
const string STUDENT_ID   = "C243236";
const string ALGO_NAME    = "Merge Sort";

void merge_arrays(vector<int>& arr, int left, int mid, int right) {
    int lLen = mid - left + 1;
    int rLen = right - mid;

    vector<int> L(lLen), R(rLen);
    for (int i = 0; i < lLen; ++i) L[i] = arr[left + i];
    for (int i = 0; i < rLen; ++i) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < lLen && j < rLen) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }
    while (i < lLen) arr[k++] = L[i++];
    while (j < rLen) arr[k++] = R[j++];
}

void merge_sort_recursive(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_recursive(arr, left, mid);
        merge_sort_recursive(arr, mid + 1, right);
        merge_arrays(arr, left, mid, right);
    }
}

void merge_sort(vector<int>& arr) {
    merge_sort_recursive(arr, 0, (int)arr.size() - 1);
}

void benchmark(int size) {
    vector<int> arr = generateArray(size);

    auto start = chrono::high_resolution_clock::now();
    merge_sort(arr);
    auto end   = chrono::high_resolution_clock::now();

    double elapsed = chrono::duration<double>(end - start).count();

    cout << "------------------------------"          << "\n"
         << "Student Name   : " << STUDENT_NAME       << "\n"
         << "Student ID     : " << STUDENT_ID         << "\n"
         << "Algorithm      : " << ALGO_NAME          << "\n"
         << "Input Size     : " << size               << "\n"
         << "Execution Time : " << fixed << setprecision(8)
                                << elapsed << " seconds\n";
}

int main() {
    int sizes[] = {10, 100, 1000, 10000, 100000};
    for (int s : sizes) {
        benchmark(s);
    }
    cout << "==============================" << "\n";
    return 0;
}