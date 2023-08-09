#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
void dfs(int node,int parent)
{
    int flag=1;
    //cout<<node<<"->";
    // if(graph[node].size()==0) {cout<<node<<"->";return;}
    for(auto child:graph[node])
    {
        if(child!=parent) {flag=0;dfs(child,node);}
    }
    if(flag) cout<<node<<"->";
}
int main()
{
    cout<<"Enter the number of nodes in the tree:";
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
    int root;
    cout<<"Enter the root of the tree:";
    cin>>root;
    dfs(root,0);
  // for(auto it:graph) cout<<it.size()<<endl;

    return 0;
}