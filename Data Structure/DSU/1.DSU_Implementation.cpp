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
int parent[N];
int sizee[N];
void make(int v){
    parent[v]=v;
    sizee[N]=1;
}
int find(int v){
    if(parent[v]==v) return v;
    return parent[v] = find(parent[v]); //path compression
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sizee[a]<sizee[b]) swap(a,b);
        parent[b]=a;
        sizee[a]+=sizee[b];
    }
}
void solve(int t){
    int n,m;//node,edges
    cin>>n>>m;
    for(int i=1;i<=n;i++) make(i); //make node
    while(m--){
        int a,b;cin>>a>>b; //input edges
        Union(a,b);
    }
    //no of connected component
    int cc=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i) cc++;
    }
    cout<<cc<<endl;
}
int main(){
    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}

