#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> adj[105];

    for(int i = 0; i < n; i++)
    {
        int u, k;
        cin >> u >> k;

        for(int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            adj[u].push_back(v); // directed, so only one way
        }
    }

    int dist[105];
    for(int i = 1; i <= n; i++) dist[i] = -1;

    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];

            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout << i << " " << dist[i] << "\n";

    return 0;
}

/*
========================
TEST CASE 1
========================

Input:

4 // number of vertices
// U K V1 V2 V3 ... VK here U is the vertex number, K is the number of vertices connected to U, and V1, V2, ..., VK are the vertices connected to U
1 2 2 4
2 1 4
3 0
4 1 3

Output:

1 0
2 1
3 2
4 1

Explanation:

1 to distace of 1 = 0
2 to distace of 1 = 1 (1 -> 2)
3 to distace of 1 = 2 (1 -> 4 -> 3)
4 to distace of 1 = 1 (1 -> 4)

*/