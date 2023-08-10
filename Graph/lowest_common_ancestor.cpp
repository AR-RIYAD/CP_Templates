#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
vector<int> parent;
void dfs(int node,int par=-1)
{
    parent[node]=par;
    for(auto child:tree[node])
    {
        if(child!=par) dfs(child,node);
    }
}
vector<int> path(int node)
{
    vector<int> res;
    while(node!=-1)
    {
        res.push_back(node);
        node=parent[node];
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    int n;
    cout<<"Enter the number of nodes in the tree:";
    cin>>n;
    tree.resize(n+1);
    parent.resize(n+1);
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
    int x,y;
    cout<<"Enter two nodes which lca to be determines:";
    cin>>x>>y;
    vector<int> pathx=path(x);
    vector<int> pathy=path(y);
    int lca=-1,mn_length=min(pathx.size(),pathy.size());
    //cout<<mn_length<<endl;
    for(int i=0;i<mn_length;i++)
    {
        if(pathx[i]==pathy[i]) lca=pathx[i];
        else break;
    }
    cout<<lca<<endl;
    
    return 0;
    

}