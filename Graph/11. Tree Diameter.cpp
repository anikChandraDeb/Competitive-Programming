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
#define nline "\n"
vector<int> adj[N];
bool vis[N];

int maxD,maxNode;
void dfs(int v,int dis){
    vis[v]=1;

    if(dis>maxD) maxD=dis,maxNode=v;

    for(auto child:adj[v]){
        if(!vis[child]){
            dfs(child,dis+1);
        }
    }
}

void solve(int t){
    int n,m;//vertex,edge no
    cin>>n;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u); //if directed remove this line
    }
    //do here
    int diaNode1,diaNode2;
    maxD=-1;
    dfs(1,0);
    diaNode1=maxNode;
    memset(vis,0,sizeof(vis));

    maxD=-1;
    dfs(maxNode,0);
    diaNode2=maxNode;
    //cout<<"Diameter terminal node"<<" "<<diaNode1<<" "<<diaNode2<<nline;
    //cout<<"Diameter length: "<<maxD<<nline;
    cout<<maxD<<nline;
}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
