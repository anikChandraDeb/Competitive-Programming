/*  Anik Deb -> CSE,DUET
    Praying(Everything is depend on God):
    Hare Krishna Hare Krishna
    Krishna Krishna Hare Hare
    Hare Rama Hare Rama
    Rama Rama Hare Hare
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define N 1001
bool vis[N][N];
int n,m;//row,col

bool isValid(int x,int y){

    if(x<1 || x>n || y<1 || y>m) return false;
    if(vis[x][y]==true) return false;
    return true;
}
//direction array initialize
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x,int y){
    vis[x][y]=1;
    cout<<x<<" "<<y<<endl;

    for(int i=0;i<4;i++)
        if(isValid(x+dx[i],y+dy[i]))
            dfs(x+dx[i],y+dy[i]);
//    if(isValid(x-1,y)) // up
//        dfs(x-1,y);
//    if(isValid(x,y+1)) //right
//        dfs(x,y+1);
//    if(isValid(x+1,y)) // down
//        dfs(x+1,y);
//    if(isValid(x,y-1)) //left
//        dfs(x,y-1);
}
void solve(int t){
    cin>>n>>m;
    dfs(1,1);
}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
