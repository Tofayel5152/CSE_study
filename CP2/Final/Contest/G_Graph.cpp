#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int graph[101][101] = {0};

    for (int i = 0; i < n; i++)
    {
        int u, k;

        cin >> u >> k;

        for (int j = 0; j < k; j++)
        {
            int v;
            cin >> v;

            graph[u][v] = 1;
        }
    }

    // Print adjacency matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << graph[i][j];

            if (j < n)
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}


/*

========================
TEST CASE
========================

Input:

4
1 2 2 4
2 1 4
3 0
4 1 3


Output:

0 1 0 1
0 0 0 1
0 0 0 0
0 0 1 0

*/