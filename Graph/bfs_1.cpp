#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int> adj_list[N];
vector<bool> visited(N,false);

void bfs(int start){

    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int current=q.front();
        q.pop();
        if(!visited[current])
        {
            visited[current]=true;
            cout<<current<<"->";
        
            for(auto u:adj_list[current])
            {
                if(!visited[u]) q.push(u);
            }
        }
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
    int start;
    cout<<"Enter starting Node:";
    cin>>start;
    bfs(start);

    return 0;
}