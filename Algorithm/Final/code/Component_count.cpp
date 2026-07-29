#include<bits/stdc++.h>

using namespace std;

const int N=1e5;
int component=0;

int visited[N];

vector<int> adj_list[N];

void dfs(int node)
{
    cout<<node<< " ";
    visited[node]=1;
    component++;

    for (int adj_node: adj_list[node])
    {
       if(visited[adj_node]==0)
        dfs(adj_node);
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

    int src=0;
    dfs(src);
    cout<<"\nNumber of component: "<<component<<endl;
}


/*
0----1 ---- 2----3
     |     |
     |     |
     5-----4

     Nodes =6
     edges =6

Test case:
6 6

0 1
1 5
5 4
4 2
2 3
1 2

output:
0 1 5 4 2 3 
Number of component: 6
 */
