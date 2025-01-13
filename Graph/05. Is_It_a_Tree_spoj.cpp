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

void dfs(int v){
    vis[v]=1;

    for(int i=0;i<adj[v].size();i++){
        int child=adj[v][i];
        if(vis[child]==0)
            dfs(child);
    }
}

void solve(int t){
    int n,m;//vertex,edge no
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u); //if directed remove this line
    }
    //do here

    //hackerearth
    int cc_count=0;
    for(int i=1;i<=n;i++)
        if(!vis[i]) cc_count++,dfs(i);
    if(cc_count==1 && m==n-1) cout<<"YES"<<nline;
    else cout<<"NO"<<nline;
}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
