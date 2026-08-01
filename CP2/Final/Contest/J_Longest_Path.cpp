#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[100005];

    int indegree[100005] = {0};
    int dp[100005] = {0};

    // Input edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);

        indegree[v]++;
    }

    queue<int> q;

    // Put all vertices with indegree 0
    // into the queue
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Topological sort + DP
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // Visit all vertices connected from u
        for (int v : graph[u])
        {
            // Update longest path to v
            dp[v] = max(dp[v], dp[u] + 1);

            // Remove edge u -> v
            indegree[v]--;

            // If v has no incoming edges left
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    // Find maximum DP value
    int answer = 0;

    for (int i = 1; i <= n; i++)
    {
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;

    return 0;
}


/*

========================
TEST CASE
========================

Input:

4 5
1 2
1 3
3 2
2 4
3 4


Output:

3


Longest path:

1 -> 3 -> 2 -> 4

Number of edges = 3

*/