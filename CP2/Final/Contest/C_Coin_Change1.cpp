#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000007;

int main()
{
    int T;
    cin >> T;

    // Run for each test case
    for (int tc = 1; tc <= T; tc++)
    {
        int n, K;
        cin >> n >> K;

        int A[51];   // Coin values
        int C[51];   // Maximum number of each coin

        // Input coin values
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i];
        }

        // Input maximum usage of each coin
        for (int i = 1; i <= n; i++)
        {
            cin >> C[i];
        }

        // dp[i][j] = number of ways to make amount j
        // using the first i types of coins
        int dp[51][1001] = {};

        // Base case:
        // There is 1 way to make amount 0: use no coins
        dp[0][0] = 1;

        // Go through each coin type
        for (int i = 1; i <= n; i++)
        {
            // Try to make every amount from 0 to K
            for (int j = 0; j <= K; j++)
            {
                // Try using the current coin
                // 0 times, 1 time, 2 times, ... C[i] times
                for (int x = 0; x <= C[i]; x++)
                {
                    // Total value if we use x current coins
                    int cost = x * A[i];

                    // If the cost becomes bigger than the amount we are trying to make, stop
                    if (cost > j)
                    {
                        break;
                    }

                    // Add ways from previous coin types
                    dp[i][j] += dp[i - 1][j - cost];

                    // Keep answer within MOD
                    dp[i][j] %= MOD;
                }
            }
        }

        // Final answer
        cout << "Case " << tc << ": " << dp[n][K] << endl;
    }

    return 0;
}

/*

=========================
SAMPLE INPUT
=========================

2
3 5
1 2 5
3 2 1
4 20
1 2 3 4
8 4 2 1


=========================
SAMPLE OUTPUT
=========================

Case 1: 3
Case 2: 9


=========================
HOW TO READ TEST CASE 1
=========================

3 5
↑ ↑
n K

n = 3
There are 3 types of coins.

K = 5
We want to make amount 5.

Coin values:
1 2 5

Maximum uses:
3 2 1

So:

Coin 1 → maximum 3 times
Coin 2 → maximum 2 times
Coin 5 → maximum 1 time

Ways to make 5:

1 + 1 + 1 + 2
1 + 2 + 2
5

Total = 3 ways

*/