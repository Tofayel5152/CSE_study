#include <bits/stdc++.h>
#include "random_int_array_generator.h"
using namespace std;

const string STUDENT_NAME = "Tofayel Ahmmed";
const string STUDENT_ID   = "C243236";
const string ALGO_NAME    = "Quick Sort";

int partition(vector<int>& arr, int low, int high) {
    int pivotIdx = low + rand() % (high - low + 1);
    swap(arr[pivotIdx], arr[high]);

    int pivot = arr[high];
    int i     = low;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            ++i;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quicksort_recursive(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort_recursive(arr, low, p - 1);
        quicksort_recursive(arr, p + 1, high);
    }
}

void quick_sort(vector<int>& arr) {
    if (arr.empty()) return;
    quicksort_recursive(arr, 0, (int)arr.size() - 1);
}

void benchmark(int size) {
    vector<int> arr = generateArray(size);

    auto start = chrono::high_resolution_clock::now();
    quick_sort(arr);
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
    srand((unsigned)time(nullptr));
    int sizes[] = {10, 100, 1000, 10000, 100000};
    for (int s : sizes) {
        benchmark(s);
    }
    cout << "==============================" << "\n";
    return 0;
}