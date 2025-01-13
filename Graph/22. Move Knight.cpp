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
#define N 9
bool vis[N][N];
int dist[N][N];
int knight[N][N];
int n,m;//row,col
int present=1; //starting with 1
bool isValid(int x,int y){

    if(x<1 || x>n || y<1 || y>m) return false;
    if(vis[x][y]==true) return false;
    return true;
}
//direction array initialize
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};

void bfs(int srcx,int srcy){
    queue<pair<int,int> > q;
    q.push({srcx,srcy});
    vis[srcx][srcy]=1;
    dist[srcx][srcy]=0;

    while(!q.empty()){
        int currx=q.front().first;
        int curry=q.front().second;
        q.pop();

        for(int i=0;i<8;i++)
        if(isValid(currx+dx[i],curry+dy[i])){
            int newx=currx+dx[i];
            int newy=curry+dy[i];
            vis[newx][newy]=1;
            q.push({newx,newy});
            dist[newx][newy]=dist[currx][curry]+1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<dist[i][j]<<" ";cout<<endl;
    }
}

void solve(int t){
    n=8,m=8;
    char sc,tc;
    int sr,tr;     //codechef move knights
    cin>>sc>>sr;
    cin>>tc>>tr;
    bfs(sr,sc-'a'+1);
    cout<<dist[tr][tc-'a'+1]<<endl;

}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
