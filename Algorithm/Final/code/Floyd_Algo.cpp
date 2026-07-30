#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX; 

int main() {
    int V, E, u, v, w;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    int dist[V+1][V+1];

    for (int i = 0; i <= V; i++){
        for (int j = 0; j <= V; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    cout << "Enter the edges (u v w) use -1 for no edge:" << endl;
    for (int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            if (u != -1 && v != -1 && w != -1)
                dist[u][v] = w;

        }
    
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
sample Input:
4 4
0 1 3
0 3 7
1 2 1
2 3 2

output:
    0      3      4      6
    INF      0      1      3
    INF    INF      0      2
    INF    INF    INF      0

*/