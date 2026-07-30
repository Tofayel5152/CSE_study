#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, u, v, w;
    cin >> n >> e;
    bool reachable[n+1][n+1];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            reachable[i][j] =false;

    while(e--) {
        cin >> u >> v >> w;
        reachable[u][v] = true;
    }

    // intermediary node i
    for(int i = 1; i <= n; i++){
        for(u = 1; u <= n; u++){
            for(v = 1; v <= n; v++){
                reachable[u][v] = reachable[u][v] || (reachable[u][i] && reachable[i][v]);
            }
        }
    }

    for(u = 1; u <= n; u++){
        for(v = 1; v <= n; v++){
            cout << reachable[u][v] << " ";
        }
        cout << endl;
    }
}

/*
sample Input:
4 4
1 2 1
2 4 1
4 1 1
4 3 1

output:
1 1 1 1
1 1 1 1
0 0 0 0
1 1 1 1

*/