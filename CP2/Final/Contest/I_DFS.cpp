#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
bool visited[105];
int disc[105], fin[105];
int timer = 1;

void dfs(int u)
{
    visited[u] = true;
    disc[u] = timer++;

    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(!visited[v])
            dfs(v);
    }

    fin[u] = timer++;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int u, k;
        cin >> u >> k;

        for(int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            adj[u].push_back(v);
        }
    }

    // run DFS from every unvisited vertex, in ID order
    for(int u = 1; u <= n; u++)
    {
        if(!visited[u])
            dfs(u);
    }

    for(int i = 1; i <= n; i++)
        cout << i << " " << disc[i] << " " << fin[i] << "\n";

    return 0;
}

/*
========================
TEST CASE 1
========================

Input:

4
1 1 2 // U K V1 V2 V3 ... VK here U is the vertex number, K is the number of vertices connected to U, and V1, V2, ..., VK are the vertices connected to U
2 1 4
3 0
4 1 3

Output:

1 1 8
2 2 7
3 4 5
4 3 6

Explanation:
// Graph:
1 → 2
2 → 4
4 → 3

// DFS traversal with timer: vertex(timer) timer++ for every step.
-> 1 (1) → 2 (2) -> 4 (3) → 3 (4) then backtrack -> 3 (5) → 4 (6) → 2 (7) → 1 (8)

*/