#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj[100];

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this line if the graph is directed
    }

    for(int i = 1; i <= n; i++)
    {
        cout << i << ": ";

        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";

        cout << endl;
    }

    return 0;
}

/*
 *For weighted graph.

int n, e;
    cin >> n >> e;

    vector<pair<int,int>> graph[100];  // Adjacency list representation of the graph

    // Input edges
    for(int i=0; i<e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});   // Remove if directed
    }

*/

/*
Sample Input:
4 4
1 2
1 3
2 4
3 4
Sample Output:
1: 2 3 
2: 1 4 
3: 1 4 
4: 2 3 
*/