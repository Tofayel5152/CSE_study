#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[100];

    for(int i = 0; i < n; i++)
        cin >> a[i];
    // sort(a, a + n);   // Sort the array
    int target;
    cin >> target;

    int low = 0, high = n - 1;
    int pos = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(a[mid] == target)
        {
            pos = mid;
            break;
        }
        else if(a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(pos == -1)
        cout << "Not Found";
    else
        cout << "Found at index " << pos;

    return 0;
}

/*
Sample Input:
5
1 3 5 7 9
7
Sample Output:
Found at index 3


If data is not sorted, then we need to sort the data first.
We can use the sort() function, like this: sort(a, a+n);
*/