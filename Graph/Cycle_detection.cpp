#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
vector<int> graph[N];
vector<bool> visited(N,false);
vector<int> route;
bool isCycle=false;
bool dfs(int node,int parent)
{
    visited[node]=true;
    route.push_back(node);
    for(auto child:graph[node])
    {
        if(visited[child] && child==parent) continue;
        if(visited[child])
        {
            return true;s
        }
        isCycle|=dfs(child,node);
        
    }
    return isCycle;
}
int main()
{
    cout<<"Enter number of nodes and edges:";
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cout<<"Enter two connected edges:";
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,0)) isCycle=true;
        }
    }
    if((isCycle)) cout<<"Loop exist"<<endl;
    else cout<<"Loop doesn't exist"<<endl;
    
    return 0;
}