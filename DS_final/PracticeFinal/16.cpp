/*Q3. Traverse a graph using Depth First Search (DFS).
Sample Input
Enter vertices: 5
Enter edges:
0 1
0 2
1 3
2 4
Start vertex: 0
Sample Output
DFS Traversal: 0 1 3 2 4
*/
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

int main() {
    int vertices;
    cout << "Enter vertices: ";
    cin >> vertices;
    
    vector<int> adjList[vertices];
    
    cout << "Enter edges:\n";
    int v1, v2;
    
    // Assuming 5 edges as per sample
    for (int i = 0; i < vertices - 1; i++) {
        cin >> v1 >> v2;
        if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices) {
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
    }
    
    int start;
    cout << "Start vertex: ";
    cin >> start;
    
    vector<bool> visited(vertices, false);
    
    cout << "DFS Traversal: ";
    DFSUtil(adjList, visited, start);
    cout << endl;
    
    return 0;
}