#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int adj[100][100] = {0};

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v; // >> w (weight)

        adj[u][v] = 1; // adj[u][v] = w; // Add weight if the graph is weighted
        adj[v][u] = 1; // Remove this line if the graph is directed
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << adj[i][j] << " ";

        cout << endl;
    }

    return 0;
}

/*
Sample Input:
4 6
1 2
1 3
1 4
2 3
2 4
3 4
Sample Output:
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0
*/