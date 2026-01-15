/*6. Write a program to display the adjacency matrix of a graph.*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertices;
    cout << "Enter vertices: ";
    cin >> vertices;

    vector<vector<int>> matrix(vertices, vector<int>(vertices, 0));

    cout << "Enter edges (vertex1 vertex2, enter -1 -1 to stop):\n";
    int v1, v2;
    while (true) {
        cin >> v1 >> v2;
        if (v1 == -1 && v2 == -1) break;
        if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices) {
            matrix[v1][v2] = 1;

            // matrix[v2][v1] = 1; // For undirected graphs
        }
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}