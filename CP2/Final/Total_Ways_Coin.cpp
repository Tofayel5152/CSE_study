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
    dp[0] = 1;  // 1 way to make amount 0 (use no coins)
    for(int i = 1; i <= amount; i++)
        dp[i] = 0;

    for(int j = 0; j < n; j++)          // loop coins outer
    {
        for(int i = coin[j]; i <= amount; i++)  // loop amount inner
        {
            dp[i] += dp[i - coin[j]];
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
5

    Explanation:
    The 5 ways to make amount 5 using coins of denominations 1, 2, and 3 are:
    1. 1+1+1+1+1
    2. 1+1+1+2
    3. 1+2+2
    4. 2+3
    5. 1+1+3
*/