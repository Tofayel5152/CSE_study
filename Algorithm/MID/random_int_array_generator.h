/*#include "random_int_array_generator.h"*/
#ifndef RANDOM_INT_ARRAY_GENERATOR
#define RANDOM_INT_ARRAY_GENERATOR

#include <bits/stdc++.h>
using namespace std;

vector<int> generateArray(int size) {
    static bool seeded = false;
    if (!seeded) {
        srand((unsigned)time(0));
        seeded = true;
    }

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000000 + 1;
    }
    return arr;
}

#endif