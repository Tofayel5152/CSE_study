#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    const int MOD = 1000000007;

    // dp[i] = number of ways to make sum i
    vector<long long> dp(x + 1, 0);

    // Base case
    // There is 1 way to make sum 0: use nothing
    dp[0] = 1;

    // Calculate number of ways for each sum
    for(int sum = 1; sum <= x; sum++)
    {
        // Try every coin
        for(int i = 0; i < n; i++)
        {
            if(sum - coins[i] >= 0)
            {
                dp[sum] =
                    (dp[sum] + dp[sum - coins[i]]) % MOD;
            }
        }
    }

    cout << dp[x] << endl;

    return 0;
}

/*
* Same as Total_Ways_Coin.cpp
========================
TEST CASE 1
========================

Input:
3 9
2 3 5

Output:
8

Ways:
2 + 2 + 5
2 + 5 + 2
5 + 2 + 2
3 + 3 + 3
2 + 2 + 2 + 3
2 + 2 + 3 + 2
2 + 3 + 2 + 2
3 + 2 + 2 + 2


========================
TEST CASE 2
========================

Input:
3 5
2 3 5

Output:
3

Ways:
2 + 3
3 + 2
5


========================
TEST CASE 3
========================

Input:
2 4
1 2

Output:
5

Ways:
1 + 1 + 1 + 1
1 + 1 + 2
1 + 2 + 1
2 + 1 + 1
2 + 2
*/