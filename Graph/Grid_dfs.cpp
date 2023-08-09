#include<bits/stdc++.h>
using namespace std;
int const N=1e2;
int r,c;
bool visited[N][N];
bool is_valid(int x,int y)
{
    if(x<1||x>r||y<1||y>c) return false;
    if(visited[x][y]) return false;
    return true;
}
int dx[]={-1,0,1,0};  //up->right->down->left(clockwise)
int dy[]={0,1,0,-1};
void dfs(int x,int y)
{
    visited[x][y]=true;
    cout<<x<<" "<<y<<endl;
    for(int i=0;i<4;i++){
        if(is_valid(x+dx[i],y+dy[i]))
        {
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
int main(){
    cout<<"Enter the row and column number: ";
    cin>>r>>c;
    int x,y;
    cout<<"Enter starting node:";
    cin>>x>>y;
    dfs(x,y);

    return 0;
}