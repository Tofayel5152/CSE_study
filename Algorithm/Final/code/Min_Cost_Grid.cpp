#include <bits/stdc++.h>
using namespace std;

const int n=3, m=3;

int minCost(int cost[n][m]) {

    for(int i=1;i<n;i++)
        cost[i][0]=cost[i-1][0]+cost[i][0];

    for(int j=1;j<m;j++)
        cost[0][j]=cost[0][j-1]+cost[0][j];

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            cost[i][j]=cost[i][j]+min(cost[i-1][j],cost[i][j-1]); // change min to max if you want to find the maximum cost
        }
    }

    return cost[n - 1][m - 1];
}

int main() {
  
    int cost[n][m] = {
        {1, 2, 3}, // 1 3 6 (min cost to reach 0,0 to n,m)  // 1 3 6 (max cost to reach 0,0 to n,m)
        {4, 8, 2}, // 5 11 8                                // 5 13 15
        {1, 5, 3} // 6 11 11                                // 6 18 21
    };

    cout << minCost(cost);
    return 0;
}
