#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
int mx=0;
int dfs(int node,int level)
{
    visited[node]=true;
    for(int adj:graph[node])
    {
        if(!visited[adj])
        {
            dfs(adj,level+1);
        }
    }
    mx=max(mx,level);
    return mx;
}
int main()
{
    cout<<"Enter number of node and edges:";
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<m;i++)
    {
        cout<<"Enter two connected components:";
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int mxl=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i]) mx=max(mx,dfs(i,1));
    }
   cout<<mx<<endl;

    return 0;
}