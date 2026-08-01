#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    /* Check:
    bool prime = true;
    if(n <= 1)
        prime = false;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            prime = false;
            break;
        }
    }
    if(prime)
        cout << "Prime";
    else
        cout << "Not Prime";


Sample Input:
10
Sample Output:
Not Prime
        */

    for(int i = 2; i <= n; i++)
    {
        bool prime = true;

        for(int j = 2; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                prime = false;
                break;
            }
        }

        if(prime)
            cout << i << " ";
    }
    

    return 0;
}

/*
Sample Input:
10
Sample Output:
2 3 5 7 
*/