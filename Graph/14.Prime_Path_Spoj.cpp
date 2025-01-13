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

vector<int> prime;
void primeCal(){
    for(int n=1000;n<=9999;n++){
        bool fg=1;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){fg=0;break;}
        }
        if(fg) prime.pb(n);
    }
}
#define N 20005
vector<int> adj[N];
bool vis[N];
int dis[N];
int diff(int a,int b){
    int d=0;
    while(a && b){
        if(a%10!=b%10) d++;
        a/=10,b/=10;
    }
    return d;
}
void edgeCal(){
    for(int i=0;i<prime.size();i++){
        for(int j=0;j<prime.size();j++){
            if(diff(prime[i],prime[j])==1){
                adj[prime[i]].pb(prime[j]);
            }
        }
    }
//    for(int i=1000;i<=9999;i++){
//        if(count(prime.begin(),prime.end(),i)){
//            for(int j=0;j<adj[i].size();j++) cout<<adj[i][j]<<" ";cout<<endl;
//        }
//    }
}



void bfs(int v,int d){
    vis[v]=1;
    dis[v]=d;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto child:adj[curr]){
            if(!vis[child]){
                dis[child]=dis[curr]+1;
                q.push(child);
                vis[child]=1;
            }
        }
    }
}

void solve(int t){
    int a,b;
    cin>>a>>b;
    memset(vis,-1,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    //do here
    bfs(a,0);
    //distance from node a to ohter node
    if(dis[b]!=-1) cout<<dis[b]<<endl;
    else cout<<"Impossible"<<endl;
}
int main(){
    primeCal();
    edgeCal();
    int tt=1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
