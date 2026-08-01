#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool visited[100];

void dfs(int u)
{
    visited[u] = true;
    cout << u << " ";

    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(!visited[v])
            dfs(v);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    dfs(start);

    return 0;
}

/*
Sample Input:
5 4
0 1
1 2
2 3
3 4
0
Sample Output:
0 1 2 3 4
*/