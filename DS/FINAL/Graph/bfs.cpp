#include<bits/stdc++.h>

using namespace std;

const int N=1e5;

int visited[N]; // int sum[10]={0,0,0,0,0,0,0,0,0}

vector<int> adj_list[N]; // ={(0,1), (0,2), .......}

void bfs(int src)
{
    queue<int>q;
   visited[src]=1;
   q.push(src);


while (!q.empty())
{
    int head =q.front();

    q.pop();

    cout<<head<<endl;

for (int adj_node: adj_list[head])
    {
       if(visited[adj_node]==0) {
        visited[adj_node]=1;
        q.push(adj_node);
       }
    }

}
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    for (int  i = 0; i < edges; i++)
    {
       int u,v;
       cin>>u>>v;
       adj_list[u].push_back(v);
       adj_list[v].push_back(u);
    }

    int src=4;
    bfs(src);
    return 0;

}


/*
0----1-----2----3
     |     |
     |     |
     5-----4

     Nodes =6
     edges =5

6 6

0 1
1 5
5 4
4 2
2 3
1 2
 */
