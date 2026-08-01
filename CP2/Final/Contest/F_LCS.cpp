#include <bits/stdc++.h>
using namespace std;

int dp[3001][3001];

int main()
{
    string s, t;

    cin >> s;
    cin >> t;

    int n = s.size();
    int m = t.size();

    // Build the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // If characters are same
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            // If characters are different
            else
            {
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
            }
        }
    }

    // Now find the actual LCS string
    string answer = "";

    int i = n;
    int j = m;

    while (i > 0 && j > 0)
    {
        // Same character means it is part of LCS
        if (s[i - 1] == t[j - 1])
        {
            answer += s[i - 1];

            i--;
            j--;
        }

        // Move toward the bigger DP value
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }

        else
        {
            j--;
        }
    }

    // We found the LCS backwards
    reverse(answer.begin(), answer.end());

    cout << answer << endl;

    return 0;
}


/*

========================
TEST CASE
========================

Input:

axyb
abyxb


Output:

axb


Note:

"ayb" is also a correct answer.

*/