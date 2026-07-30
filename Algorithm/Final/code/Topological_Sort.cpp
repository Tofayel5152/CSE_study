#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> graph[100];
    int indegree[100] = {0};

    // Input edges
    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v); // Directed edge from u to v
        indegree[v]++;
    }

    queue<int> q;

    // Put all nodes with indegree 0 into the queue
    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    // Process the queue
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        // Visit all neighbors
        for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];

            indegree[v]--;

            if(indegree[v] == 0)
                q.push(v);
        }
    }

    return 0;
}

/*
 * node numbering starts from 1
Sample Input

6 6
1 2
1 3
2 4
3 4
4 5
5 6

Sample Output

1 2 3 4 5 6

*/