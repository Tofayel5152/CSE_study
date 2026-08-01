#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;

    int wt[100], val[100];

    for(int i = 0; i < n; i++)
        cin >> wt[i];

    for(int i = 0; i < n; i++)
        cin >> val[i];

    int dp[101][101];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(wt[i-1] <= j)
            {
                int take = val[i-1] + dp[i-1][j-wt[i-1]];
                int leave = dp[i-1][j];
                dp[i][j] = (take > leave) ? take : leave;
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][W];

    return 0;
}

/*
Sample Input:
3 50
10 20 30
60 100 120
Sample Output:
220

    Explanation:
    The maximum value that can be obtained is 220 by taking items with weights 20 and 30.
*/