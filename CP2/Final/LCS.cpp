#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int dp[101][101];

    for(int i = 0; i <= a.length(); i++)
    {
        for(int j = 0; j <= b.length(); j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }

    cout << dp[a.length()][b.length()];

    return 0;
}

/*
Sample Input:
axyb
abyxb
Sample Output:
3

    Explanation:
    The longest common subsequence is "ayb", so the answer is 3.
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int n = a.length(), m = b.length();
    int dp[101][101];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }

    string result = "";
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(a[i-1] == b[j-1])
        {
            result += a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1])   // changed > to >=
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(result.begin(), result.end());

    cout << result << "\n";   // just the string now

    return 0;
}

Sample Input:
axyb
abyxb
Sample Output:
axb
*/