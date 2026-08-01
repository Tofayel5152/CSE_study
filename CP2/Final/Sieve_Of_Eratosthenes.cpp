#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i <= n; i++)
    {
        if(isPrime[i])
        {
            for(int j = i*i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    for(int i = 2; i <= n; i++)
        if(isPrime[i])
            cout << i << " ";

    return 0;
}

/*
Sample Input:
30
Sample Output:
2 3 5 7 11 13 17 19 23 29
*/