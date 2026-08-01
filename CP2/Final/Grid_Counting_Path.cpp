#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;

    int dp[101][101];

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[row-1][col-1];

    return 0;
}

/*
Sample Input:
3 3
Sample Output:
6
    Explanation:
    The number of unique paths from the top-left corner to the bottom-right corner of a 3x3 grid is 6.
    Right, Right, Down, Down
    Right, Down, Right, Down
    Down, Right, Right, Down
    Down, Down, Right, Right
    Down, Right, Down, Right
    Right, Down, Down, Right
*/