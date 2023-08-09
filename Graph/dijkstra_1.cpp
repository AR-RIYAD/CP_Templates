#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int INF=1e9;
vector<pair<int,int>> graph[N];
vector<int> dist(N,INF);
void dijkstra(int source)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,source});
    dist[source]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(d>dist[u]) continue;

        for(auto it:graph[u])
        {
            int v=it.first;
            int w=it.second;
            if(dist[v]>dist[u]+w) 
            {
            dist[v]=dist[u]+w;
            pq.push({dist[v],v});
            }
        }
    }
}

int main()
{
    int n,m;
    cout<<"Enter number of nodes and edges:";
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;
        cout<<"Enter two nodes and weight:";
        cin>>x>>y>>w;
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
    }
    cout<<"Enter the source node:";
    int source;
    cin>>source;
    dijkstra(source);
    for(int i=1;i<=n;i++)
    {
        cout<<"Distance of "<<i<<" from "<<source<<" is: "<<dist[i]<<endl;
    }

    return 0;
}