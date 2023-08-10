#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
void dfs(int node,int parent=0)
{
    //cout<<node<<"->";
    int flag=1;
    for(auto child:graph[node])
    {
        if(child!=parent) {flag=0;dfs(child,node);}
    }
    if(flag) cout<<node<<"->";
}
int main()
{
    int n;
    cout<<"Enter the number of node of the tree:";
    cin>>n;
    graph.resize(n+1);
    for(int i=0;i<n-1;i++)
    {
        cout<<"Enter two connected nodes:";
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int root;
    cout<<"Enter the root node of the tree:";
    cin>>root;
    dfs(root);

    return 0;
}