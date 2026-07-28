#include <bits/stdc++.h>
using namespace std;

// Optimize Bubble Sort function
void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
            swapped = true;
        }
        if (!swapped)
        {
            break;
        }
    }
}

// Print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);

    return 0;
}