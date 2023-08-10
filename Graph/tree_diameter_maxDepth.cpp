#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
vector<int> depth;
void dfs(int node,int parent=0)
{
    for(auto child:tree[node])
    {
        if(child!=parent) {depth[child]=depth[node]+1; dfs(child,node);}
    }
}
int main()
{
    int n;
    cout<<"Enter the number of node of the tree:";
    cin>>n;
    tree.resize(n+1);
    depth.resize(n+1);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cout<<"Enter two connected nodes:";
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    cout<<"Enter the root of the tree:";
    int root;
    cin>>root;
    dfs(root);
   // for(int i=1;i<=n;i++) cout<<i<<" depth is: "<<depth[i]<<endl; 
    int mx_depth=0,mx_dnode;
    for(int i=1;i<=n;i++) 
    {
        if(mx_depth<depth[i]) {mx_depth=depth[i]; mx_dnode=i;}
        depth[i]=0;
    }
    dfs(mx_dnode);
    
    for(int i=1;i<=n;i++)
    {
        if(mx_depth<depth[i]) mx_depth=depth[i];
    }
    cout<<"Maximum depth(diameter) is:"<<mx_depth<<endl;


    return 0;
}