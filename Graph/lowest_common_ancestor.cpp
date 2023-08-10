#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
vector<int> parent;
void bfs(int node,int parent=-1)
{
    parent[node]=parent;
    for(auto child:tree[node])
    {
        if(child!=parent) dfs(child,node);
    }
}
int main()
{
    int n;
    cout<<"Enter the number of nodes in the tree:";
    cin>>n;
    tree.resize(n+1);
    parent.resize(n+1)
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cout<<"Enter two connected nodes:";
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    cout<<"Enter the root node:";
    int root;
    cin>>root;
    dfs(root);
}