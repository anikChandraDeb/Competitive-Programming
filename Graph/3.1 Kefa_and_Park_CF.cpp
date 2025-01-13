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
vector<int> adj[N];
bool vis[N];
int a[N];
int n,m;
int ans;
void dfs(int v,int cat,int mx){
    vis[v]=1;
    if(v!=1 && (int)adj[v].size()==1 && max(mx,cat)<=m) ans++;
    for(int i=0;i<adj[v].size();i++){
        int child=adj[v][i];
        if(vis[child]==0){
            int tc;
            if(a[child]) tc=cat+1;
            else tc=0;
            //cout<<child<<" "<<cat<<endl;
            dfs(child,tc,max(mx,cat));
        }
    }
}

void solve(int t){

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u); //if directed remove this line
    }
    //do here
    if(a[1]) dfs(1,1,1);
    else dfs(1,0,1);
    cout<<ans<<endl;
}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
