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
int dis[N];
void dfs(int v,int dist){
    vis[v]=1;
    dis[v]=dist;
    for(auto child:adj[v]){
        if(vis[child]==0)
            dfs(child,dist+1);
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
    dfs(1,0);
    //distance from node 1 to ohter node
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";

    int q;cin>>q;
    int mn=INT_MAX,mncity=-1;
    while(q--){
        int girl_city;
        cin>>girl_city;
        if(dis[girl_city]<mn) mn=dis[girl_city],mncity=girl_city;
        else if(dis[girl_city]==mn && girl_city<mncity) mncity=girl_city;
    }
    cout<<mncity<<endl;

}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
