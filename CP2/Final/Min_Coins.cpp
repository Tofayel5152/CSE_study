#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, amount;
    cin >> n >> amount;

    int coin[100];

    for(int i = 0; i < n; i++)
        cin >> coin[i];

    int dp[1001];

    dp[0] = 0;

    for(int i = 1; i <= amount; i++)
        dp[i] = 1000000;

    for(int i = 1; i <= amount; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(coin[j] <= i && dp[i] > dp[i-coin[j]] + 1)
                dp[i] = dp[i-coin[j]] + 1;
        }
    }

    cout << dp[amount];

    return 0;
}

/*
Sample Input:
3 5
1 2 3
Sample Output:
2

    Explanation:
    The minimum number of coins: 3+2 = 5, so the answer is 2.
*/