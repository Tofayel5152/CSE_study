#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    double dp[3001] = {0};

    // At the beginning, we have 0 heads
    dp[0] = 1;

    // Take probability of each coin
    for (int i = 1; i <= n; i++)
    {
        double p;
        cin >> p;

        // Go backwards
        for (int j = i; j >= 0; j--)
        {
            // Current coin is TAIL
            dp[j] = dp[j] * (1 - p);

            // Current coin is HEAD
            if (j > 0)
            {
                dp[j] += dp[j - 1] * p;
            }
        }
    }

    double answer = 0;

    // More heads than tails
    for (int j = n / 2 + 1; j <= n; j++)
    {
        answer += dp[j];
    }

    cout << fixed << setprecision(10);
    cout << answer << endl;

    return 0;
}


/*

========================
TEST CASE 1
========================

Input:

3
0.5 0.5 0.5

Output:

0.5000000000


Explanation:

Possible number of heads needed:

2 heads
3 heads

Probability = 0.5

*/