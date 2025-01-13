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
vector<int> adj[N];
bool vis[N];

bool dfs(int v,int par){
    vis[v]=1;

    for(auto child:adj[v]){
        if(vis[child]==0){
            if(dfs(child,v)==true)
                return true;
        }
        else if(child!=par)
            return true;
    }
    return false;
}

void solve(int t){
    int n,m;//vertex,edge no
    cin>>n>>m;
    for(int i=1;i<=n;i++) adj[i].clear();
    memset(vis,0,sizeof(vis));

    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u); //if directed remove this line
    }
    //do here
    cout<<dfs(1,1)<<nline;
}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}

