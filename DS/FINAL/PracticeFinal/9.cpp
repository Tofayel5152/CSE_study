/*9.Write a program to traverse a graph using Depth First Search.*/
#include <bits/stdc++.h>
using namespace std;

void DFSUtil(vector<int> adj[], vector<bool> &visited, int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";
    
    for (int neighbor : adj[vertex]) {
        if (!visited[neighbor]) {
            DFSUtil(adj, visited, neighbor);
        }
    }
}

void DFS(vector<int> adj[], int vertices, int start) {
    vector<bool> visited(vertices, false);
    
    cout << "DFS Traversal: ";
    DFSUtil(adj, visited, start);
    
    // For disconnected graph
    /*
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFSUtil(adj, visited, i);
        }
    }
    */
    cout << endl;
}

int main() {
    int vertices;
    cout << "Enter vertices: ";
    cin >> vertices;
    
    vector<int> adjList[vertices];
    
    cout << "Enter edges (vertex1 vertex2, enter -1 -1 to stop):\n";
    int v1, v2;
    
    while (true) {
        cin >> v1 >> v2;
        if (v1 == -1 && v2 == -1) break;
        if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices) {
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1); // For undirected graph
        }
    }
    
    int start;
    cout << "Start vertex: ";
    cin >> start;
    
    DFS(adjList, vertices, start);
    
    return 0;
}