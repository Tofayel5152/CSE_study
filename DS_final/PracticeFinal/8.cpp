/*8. Write a program to traverse a graph using Breadth First Search.*/
#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[], int vertices, int start) {
    vector<bool> visited(vertices, false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    cout << "BFS Traversal: ";
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";
        
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
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
            
            // adjList[v2].push_back(v1); // For undirected graph
        }
    }
    
    int start;
    cout << "Start vertex: ";
    cin >> start;
    
    BFS(adjList, vertices, start);
    
    return 0;
}