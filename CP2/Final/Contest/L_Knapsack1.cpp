#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;

    long long dp[100001] = {0};

    for (int i = 1; i <= N; i++)
    {
        int weight;
        long long value;

        cin >> weight >> value;

        // Go backwards from W to weight
        for (int j = W; j >= weight; j--)
        {
            dp[j] = max(dp[j],
                        dp[j - weight] + value);
        }
    }

    cout << dp[W] << endl;

    return 0;
}


/*

========================
TEST CASE
========================

Input:

3 8
3 30
4 50
5 60


Output:

90


Explanation:

Take item 1:
Weight = 3
Value = 30

Take item 3:
Weight = 5
Value = 60

Total weight = 3 + 5 = 8
Total value  = 30 + 60 = 90

*/