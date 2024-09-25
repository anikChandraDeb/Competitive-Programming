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
vector<int> level(N,0);
vector<int> par(N,0);
void dfs(int node,int p,int l){
    par[node]=p;
    level[node]=l;
    for(auto v:adj[node]){
        if(v!=p){
            dfs(v,node,l+1);
        }
    }
}

int lca(int a,int b){
    if(level[b]<level[a]) swap(a,b);
    int d=level[b]-level[a];

    while(d>0){
        b=par[b];
        d--;
    }
    if(a==b) return a;

    while(par[a]!=par[b])
        a=par[a],b=par[b];
    return par[a];
}


void solve(int t){
    int n,m;//vertex,edge no
    cin>>n>>m;

    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u); //remove if directed
    }
    dfs(1,-1,0); //build level and parent array

//    for(int i=1;i<=n;i++) cout<<i<<" "<<par[i]<<" "<<level[i]<<endl;
    cout<<"Enter (u,v) for lca:";
    int u,v;cin>>u>>v;
    cout<<lca(u,v)<<endl;
}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
