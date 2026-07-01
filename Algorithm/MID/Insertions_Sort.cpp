#include <bits/stdc++.h>
#include "random_int_array_generator.h"
using namespace std;

const string STUDENT_NAME = "Tofayel Ahmmed";
const string STUDENT_ID   = "C243236";
const string ALGO_NAME    = "Insertion Sort";

void insertion_sort(vector<int>& arr) {
    int n = (int)arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j   = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void benchmark(int size) {
    vector<int> arr = generateArray(size);

    auto start = chrono::high_resolution_clock::now();
    insertion_sort(arr);
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