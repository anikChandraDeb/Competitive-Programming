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
#define N 10005
vector<int> adj[N];
vector<int> in(N,0);
vector<int> res;

bool khan(int n){ //node of vertex is n
    priority_queue<int, vector<int>, greater<int> > q; // for all node which indegree is zero
    for(int i=1;i<=n;i++){
        if(in[i]==0) q.push(i);
    }

    while(!q.empty()){
        int curr=q.top();
        res.pb(curr);
        q.pop();

        for(auto node:adj[curr]){
            in[node]--;
            if(in[node]==0) q.push(node);
        }
    }
    return res.size()==n;
}
void solve(int t){
    int n,m;//vertex,edge no
    cin>>n>>m;
    for(int i=0;i<N;i++) adj[i].clear();
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v; //edge u to v
        adj[u].pb(v);
        in[v]++;
    }
    //do here

    if(khan(n)){
        for(auto x:res) cout<<x<<" ";cout<<endl;
    }
    else cout<<"Sandro fails.\n";

}
/*

*/
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}

