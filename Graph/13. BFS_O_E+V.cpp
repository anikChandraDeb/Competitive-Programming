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
#define N 2000005
void initIO() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
vector<int> adj[N];
bool vis[N];
int dis[N];
void bfs(int v,int d){
    vis[v]=1;
    dis[v]=d;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto child:adj[curr]){
            if(!vis[child]){
                dis[child]=dis[curr]+1;
                q.push(child);
                vis[child]=1;
            }
        }
    }
}
void solve(int t){
    int n,m;//vertex,edge no
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u); //if directed remove this line
    }
    //do here
    bfs(1,0);
    //for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    cout<<dis[n]<<endl;
}
int main(){
    initIO();
    int tt=1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
