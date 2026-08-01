#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
    int H, W;
    cin >> H >> W;

    string grid[1001];

    // Input the grid
    for (int i = 1; i <= H; i++)
    {
        cin >> grid[i];
    }

    // dp[i][j] = number of ways
    // to reach cell (i,j)
    long long dp[1001][1001] = {};

    // Starting position
    dp[1][1] = 1;

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            // If there is a wall, skip it
            if (grid[i][j - 1] == '#')
            {
                dp[i][j] = 0;
                continue;
            }

            // Skip starting cell
            if (i == 1 && j == 1)
            {
                continue;
            }

            // Come from TOP
            if (i > 1)
            {
                dp[i][j] += dp[i - 1][j];
            }

            // Come from LEFT
            if (j > 1)
            {
                dp[i][j] += dp[i][j - 1];
            }

            dp[i][j] %= MOD;
        }
    }

    cout << dp[H][W] << endl;

    return 0;
}


/*

========================
TEST CASE
========================

Input:

3 4
...#
.#..
....


Output:

3

*/