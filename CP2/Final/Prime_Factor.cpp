#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << "Prime Factors: ";

    for(int i = 2; i * i <= n; i++)
    {
        while(n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }

    if(n > 1)
    {
        cout << n;
    }
    
    return 0;
}

/*
Sample Input:
12
Sample Output:
Prime Factors: 2 2 3
*/