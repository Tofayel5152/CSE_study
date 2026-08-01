#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[100];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int target;
    cin >> target;

    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(a[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    if(ans == n)
        cout << "No Lower Bound";
    else
        cout << "Lower Bound Index = " << ans;

    return 0;
}

/*
Sample Input:
5
1 3 5 7 9
5
Sample Output:
Lower Bound Index = 2
*/