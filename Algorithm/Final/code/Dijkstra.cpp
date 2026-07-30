#include <bits/stdc++.h>
using namespace std;

int main()
{
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

    int source;
    cin >> source;

    vector<int> dist(100, INT_MAX);  
    vector<bool> visited(100, false);

    dist[source] = 0;

    // Repeat n times
    for(int i=1; i<=n; i++)
    {
        int minDist = INT_MAX;
        int u = -1;

        // Find nearest unvisited node
        for(int j=1; j<=n; j++)
        {
            if(!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }

        visited[u] = true;

        // Update neighbors
        for(auto edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Print shortest distances
    for(int i=1; i<=n; i++)
    {
        cout << "Distance to " << i << " = " << dist[i] << endl;
    }

    return 0;
}

/*
    * node numbering starts from 1
=========================
Sample Input
=========================

5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

=========================
Sample Output
=========================

Distance to 1 = 0
Distance to 2 = 2
Distance to 3 = 3
Distance to 4 = 7
Distance to 5 = 6

*/