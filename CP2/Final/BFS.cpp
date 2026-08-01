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
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    bool visited[100] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];

            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

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