/*  Anik Deb -> CSE,DUET
    Praying(Everything is depend on God):
    Hare Krishna Hare Krishna
    Krishna Krishna Hare Hare
    Hare Rama Hare Rama
    Rama Rama Hare Hare
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
#define pb push_back
#define N 2000005
vector<int> adj[N];
bool vis[N];
int in[N],low[N];
int timer;
vector<pair<lli,lli> > bridges;
void dfs(int node,int par){
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;
    for(auto child:adj[node]){
        if(child==par) continue;  //direct parent do nothing
        if(vis[child]){
            //edge node - child is a back edge now update low
            low[node]=min(low[node] , in[child]);
        }
        else{
            //edge node - child is forward edge now check bridge condition
            dfs(child,node);
            //bridge condition
            if(low[child] > in[node])
                cout<<node<<" - "<<child<<" is a bridge"<<endl;
                //bridges.pb({node,child});
            low[node]=min(low[node],low[child]);
        }
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
    dfs(1,-1);

}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
