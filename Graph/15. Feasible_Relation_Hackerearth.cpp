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
#define N 1000005
vector<int> adj[N];
bool vis[N];
int cc[N],cc_count;
void dfs(int v){
    vis[v]=1;
    cc[v]=cc_count;
    for(int i=0;i<adj[v].size();i++){
        int child=adj[v][i];
        if(vis[child]==0)
            dfs(child);
    }
}

void solve(int t){
    int n,m;//vertex,edge no
    cin>>n>>m;
    for(int i=1;i<=n;i++) adj[i].clear();
    memset(vis,0,sizeof(vis));
    memset(cc,0,sizeof(cc));
    vector<pair<int,int> > inequality;
    for(int i=0;i<m;i++){
        int u,v;
        string c;
        cin>>u>>c>>v;
        if(c=="="){

            adj[u].pb(v);
            adj[v].pb(u); //if directed remove this line
        }
        else inequality.pb({u,v});
    }
    //do here

    //hackerearth
    cc_count=1;
    for(int i=1;i<=n;i++)
        if(!vis[i]) cc_count++,dfs(i);

    bool fg=1;
    for(int i=0;i<inequality.size();i++){
        int a=inequality[i].first;
        int b=inequality[i].second;
        if(cc[a]==cc[b]){
            fg=0;break;
        }
    }
    (fg)?cout<<"YES"<<endl:cout<<"NO"<<endl;
}
int main(){
    int tt=1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
