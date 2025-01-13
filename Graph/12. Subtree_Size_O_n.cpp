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
int subSize[N];

int dfs(int v){
    vis[v]=1;
    int curr_size=1;

    for(auto child:adj[v]){
        if(!vis[child]){
            curr_size+=dfs(child);
        }
    }
    subSize[v]=curr_size;
    return curr_size;
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
    dfs(1);
    //subtree size for 1 to n node where 1 is root
    for(int i=1;i<=n;i++) cout<<subSize[i]<<" ";
}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
