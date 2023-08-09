#include<bits/stdc++.h>
using namespace std;
int r,c;
int const n=1e2;
bool visited[n][n];
int dist[n][n];

bool is_valid(int x,int y)
{
    if(x<1||x>r||y<1||y>c) return false;
    if(visited[x][y]) return false;
    return true;
}
int dx[]={-1,0,1,0};  //up..righ..down...left(clockwise)
int dy[]={0,1,0,-1};
void bfs(int x,int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=true;
    dist[x][y]=0;
    while(!q.empty())
    {
        int currX=q.front().first;
        int currY=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(is_valid(currX+dx[i],currY+dy[i]))
            {
                int newX=currX+dx[i];
                int newY=currY+dy[i];
                visited[newX][newY]=true;
                // cout<<newX<<" "<<newY<<endl;
                dist[newX][newY]=dist[currX][currY]+1;
                q.push({newX,newY});

            }
        }
    }
}
int main()
{
    cout<<"Enter row and column:";
    cin>>r>>c;
    cout<<"Enter the starting location:";
    int x,y;
    cin>>x>>y;
    bfs(x,y);
    cout<<"Distance Array is:"<<endl;
    for(int i=1;i<=r;i++)
    {
   for(int j=1;j<=c;j++)
   {
       cout<<dist[i][j]<<"  ";
   }
   cout<<endl;
     }
    return 0;
}