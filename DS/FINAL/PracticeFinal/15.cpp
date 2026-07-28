/*Q2. Display the adjacency matrix of a graph.
Sample Input
Enter vertices: 3
Enter edges:
0 1
1 2
Sample Output
Adjacency Matrix:
0 1 0
0 0 1
0 0 0
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertices;
    cout << "Enter vertices: ";
    cin >> vertices;
    
    int matrix[vertices][vertices];
    
    // Initialize with zeros
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            matrix[i][j] = 0;
        }
    }
    
    cout << "Enter edges:\n";
    int v1, v2;
    
    // Read until EOF or invalid input
    while (cin >> v1 >> v2) {
        if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices) {
            matrix[v1][v2] = 1;
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