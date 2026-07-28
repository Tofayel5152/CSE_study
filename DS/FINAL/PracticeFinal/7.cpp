/*7. Write a program to display the adjacency list of a graph.*/
#include <bits/stdc++.h>
using namespace std;

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
    
    cout << "Adjacency List:\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}