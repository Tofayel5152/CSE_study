/*Q3. During an election campaign in the Dhaka-8 constituency, Sharif Osman Bin Hadi planned to conduct his campaign activities by starting from a central location and thoroughly
covering one area and its connected sub-areas completely before moving on to another region. His approach was to go as deep as possible into each zone before backtracking and
exploring remaining areas. Which graph traversal algorithm was most appropriate for this campaign strategy? Write code for this traversal algorithm in C++.*/
#include <bits/stdc++.h>
using namespace std;

void campaignDFS(vector<int> adj[], int vertices, int start) {
    vector<bool> visited(vertices, false);
    stack<int> s;
    
    s.push(start);
    
    cout << "Campaign route (DFS strategy): ";
    
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        
        if (!visited[current]) {
            visited[current] = true;
            cout << current << " ";
            
            // Push all unvisited neighbors to stack
            // Note: We push in reverse order to visit in natural order
            for (int i = adj[current].size() - 1; i >= 0; i--) {
                int neighbor = adj[current][i];
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int vertices, edges;
    cout << "Enter number of areas (vertices): ";
    cin >> vertices;
    
    vector<int> adjList[vertices];
    
    cout << "Enter number of connections (edges): ";
    cin >> edges;
    
    cout << "Enter connections (area1 area2):\n";
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1); // Bidirectional connections
    }
    
    int startArea;
    cout << "Enter starting area: ";
    cin >> startArea;
    
    campaignDFS(adjList, vertices, startArea);
    
    return 0;
}