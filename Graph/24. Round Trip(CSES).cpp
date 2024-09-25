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
#define N 100005
vector<int> adj[N];
bool vis[N];
vector<int> temp;
bool dfs(int node,int par){
    vis[node]=1;
    temp.push_back(node);
    for(int v:adj[node]){
        if(vis[v]==false){
            if(dfs(v,node)==true) return true;
        }
        else if(par!=v){
            temp.push_back(v);
            return true;
        }
    }
    temp.pop_back();
    return false;
}
void solve(int t){
    int n,m;//vertex,edge no
    cin>>n>>m;
    temp.clear();
    memset(vis,0,sizeof(vis));
    for(int i=0;i<N;i++) adj[i].clear();
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u); //if directed remove this line
    }
    //do here
    bool fg=0;
    for(int i=1;i<=n;i++)
        if(!vis[i]){if(dfs(i,-1)) {fg=1;break;}}
    if(fg){
        int i=0;
        for(;i<temp.size();i++){
            if(temp[i]==temp.back()) break;
        }
        cout<<(temp.size()-i)<<endl;
        for(;i<temp.size();i++) cout<<temp[i]<<" ";
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
