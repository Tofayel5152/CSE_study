#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int from, to, cost;
};

int main()
{
    int n, e, f, t, c;  
    bool is_updated;

    cin >> n >> e;

    vector<int> dis(n+1, INT_MAX); 
    vector <Edge> edges;

    for(int i = 0; i < e; i++){
        cin >> f >> t >> c;
        edges.push_back(Edge({f, t, c}));
    }

    int source = 1;
    dis[source] = 0;

    for(int it = 1; it <= n; it++){
        is_updated = false;

        for (Edge e : edges) {
        if (dis[e.from] != INT_MAX && dis[e.from] + e.cost < dis[e.to]) {
            dis[e.to] = dis[e.from] + e.cost;
            is_updated = true;
    }
}

        if(!is_updated) {
            cout << "early exited at: " << it << endl; break;
        }

        if(it == n) {
            cout << "It contains negative cycle" << endl;
            return 0;
        }

    } 

    for(int it = 1; it <= n; it++){
        cout << "distance from " << source << " to " << it << " : " << dis[it] << endl;
    }

}

/*
Test case:
5 6
1 2 4
1 3 1
3 2 -2
2 4 3
3 4 5
4 5 2


output:
early exited at: 2
distance from 1 to 1 : 0
distance from 1 to 2 : -1
distance from 1 to 3 : 1
distance from 1 to 4 : 2
distance from 1 to 5 : 4

*/