#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
vector<int> graph[N];
vector<bool> visited(N,false);
vector<int> color(N,-1);
bool biparte;
void dfs(int node,int clr)
{
   if(color[node]!=-1 && color[node]!=clr)
   {
    biparte=false;
    return;
   }
    color[node]=clr;
    if(visited[node]) return;
    visited[node]=true;
    for(auto adj:graph[node])
    {
        dfs(adj,clr^1);
    }
}
int main()
{
    int n,m;
    cout<<"Enter number of nodes and edges:";
    cin>>n>>m;
    biparte=true;
    for(int i=0;i<m;i++)
    {
        cout<<"Enter two connected nodes:";
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i]) dfs(i,0);
    }
    for(int i=1;i<=n;i++) cout<<i<<" is colored with "<<color[i]<<endl;
    if(biparte) cout<<"Graph is Biparte"<<endl;
    else cout<<"Graph is not Biparte"<<endl;

    return 0;

}