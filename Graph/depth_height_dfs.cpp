#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
 void dfs(int node,int parent=0)  //parent default value is zero if it doesn't provide
 {
    visited[node]=true;
    for(auto child:graph[node])
    {
        if(!visited[child]) 
        {
            cout<<"Going Down from "<<node<<" to "<<child<<endl;
            dfs(child,node);
        }
    }
    cout<<"Going UP from "<<node<<" to "<<parent<<endl;
 }

 int main()
 {
    cout<<"Enter number of node of the tree:";
    int n;
    cin>>n;
    graph.resize(n+1);
    visited.resize(n+1,false);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cout<<"Enter two connected nodes:";
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
 }