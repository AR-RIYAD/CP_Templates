#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
vector<int> adj_list[N];
vector<bool> visited(N,false);
void dfs(int start)
{
    if(visited[start]) return; //if already visited then return
    visited[start]=true; //mark as visited
    cout<<start<<"->"; //process
    for(auto u: adj_list[start]){
        dfs(u);
    }
}

int main(){
    int u,v;
    cout<<"Enter number of node: ";
    cin>>u;
    cout<<"Enter number of edges: ";
    cin>>v;
    for(int i=0;i<v;i++){
        int x,y;
        cout<<"Enter two connected nodes: ";
        cin>>x>>y;
        adj_list[x].push_back(y); //not directed graph
        adj_list[y].push_back(x);
    }
    cout<<"Enter the starting node:";
    int start;
    cin>>start;
    dfs(start);

    return 0;
}
