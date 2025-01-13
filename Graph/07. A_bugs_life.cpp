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
#define nline "\n"
#define N 2000005
vector<int> adj[2002];
bool vis[2002];
bool col[2002];
bool dfs(int v,int c){
    vis[v]=1;
    col[v]=c;
    for(auto child:adj[v]){
        if(vis[child]==0){
            if(dfs(child,c^1)==false)
                return false;
        }
        else if(col[v]==col[child])
            return false;
    }
    return true;
}

void solve(int t){
    int n,m;//vertex,edge no
    cin>>n>>m;
    for(int i=1;i<=n;i++) adj[i].clear();
    memset(vis,0,sizeof(vis));
    memset(col,0,sizeof(col));

    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u); //if directed remove this line
    }
    //do here

    cout<<"Scenario #"<<t<<":"<<nline;
    bool fg=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]) if(!dfs(i,0)) {fg=0;break;}
        for(int j=1;j<=n;j++) cout<<vis[j]<<" ";cout<<nline;
    }
    if(fg) cout<<"No suspicious bugs found!"<<nline;
    else cout<<"Suspicious bugs found!"<<nline;
}
int main(){
    int tt=1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
