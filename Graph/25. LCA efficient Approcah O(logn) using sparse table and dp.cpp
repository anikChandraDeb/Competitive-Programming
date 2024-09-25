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
#define N 10001
vector<int> adj[N];
vector<int> level(N,0);

const int maxN=14; //log2(N)
int LCA[N][maxN];
void dfs(int node,int p,int l){
    LCA[node][0]=p;
    level[node]=l;
    for(auto child:adj[node]){
        if(child!=p){
            dfs(child,node,l+1);
        }
    }
}
void init(int n){
    dfs(1,-1,0);
    for(int j=1;j<=maxN;j++){
        for(int i=1;i<=n;i++){
            if(LCA[i][j-1]!=-1){
                int par=LCA[i][j-1];
                LCA[i][j]=LCA[par][j-1];
            }
        }
    }
}
int lca(int a,int b){
    if(level[b]<level[a]) swap(a,b);
    int d=level[b]-level[a];
    //binary lifting
    while(d>0){
        int i=log2(d);
        b=LCA[b][i]; //move to 2^i th parent
        d-=(1<<i);
    }
    if(a==b) return a;

    for(int i=maxN;i>=0;i--){
        if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i]))
            a=LCA[a][i],b=LCA[b][i];
    }
    return LCA[a][0];
}


void solve(int t){
    int n,m;//vertex,edge no
    cin>>n>>m;

    for(int i=1;i<=n;i++) adj[i].clear();
    memset(LCA,-1,sizeof(LCA));
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u); //remove if directed
    }

    init(n);
    int q;cin>>q;
    while(q--){
        cout<<"Enter (u,v):";
        int u,v;cin>>u>>v;
        cout<<level[u]+level[v]-2*level[lca(u,v)]<<endl;
    }

}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
