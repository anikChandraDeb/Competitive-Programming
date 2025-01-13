/*  Anik Deb -> CSE,DUET
    Praying(Everything is depend on God):
    Hare Krishna Hare Krishna
    Krishna Krishna Hare Hare
    Hare Rama Hare Rama
    Rama Rama Hare Hare
*/
#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(0); cin.exceptions(ios::badbit | ios::failbit);
#define precision(n) fixed<<setprecision(n)
#define lli long long int
#define ulli unsigned long long int
#define ld long double
#define max2(x,y) ((x>y)?x:y)
#define min2(x,y) ((x<y)?x:y)
#define inv(v) for(auto& i:v) cin>>i
#define outv(v) for(auto& i:v) cout<<i<<" "
#define pi acos(-1.0)
#define nline "\n"
#define vi vector<int>
#define vlli vector<lli>
#define vc vector<char>
#define p32 pair<int,int>
#define p64 pair<lli,lli>
#define caseOP(t,o) cout<<"Case "<<t<<": "<<o<<nline
#define caseOPi(t,o) printf("Case %d: %d\n",t,o)
#define caseOPl(t,o) printf("Case %d: %lld\n",t,o)
#define caseOPd(t,o) printf("Case %d: %lf\n",t,o)
#define mod 1000000007
#define pb push_back
#define lcm(a,b) (a*b)/__gcd(a,b)
#define all(v) v.begin(),v.end()
/* For Debugging */
#define oph cout<<"H"<<nline;
#define op1(a) cout<<a<<nline;
#define op2(a,b) cout<<a<<" "<<b<<nline;

char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pbds tree<lli, null_type, less<lli>,rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
*/

void initIO() {
fast;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
lli module(lli a){
    if(a<0) return (a+2*mod)%mod; //negative modulas
    else return a%mod;
}
double eDis(double x1,double y1,double x2,double y2){
    return sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int cntHighBit(int n){
    int count=0;
    while(n){
        if(n & 1)count++;
        n>>=1;
    }
    return count;
}

//Sort pair first element ascending and 2nd element descending
bool comparator(const pair<int, int>& a,const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}
#define N 2000005
vector<int> adj[N];
bool vis[N];
lli sz=0;
void dfs(int v){
    vis[v]=1;
    sz++;
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
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u); //if directed remove this line
    }
    //do here

    //hackerearth
    int cc_count=0;
    lli ans=1;
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            sz=0;
            cc_count++,dfs(i);
            ans=(ans%mod*sz%mod)%mod;
        }
    cout<<cc_count<<" "<<ans<<endl;
}
int main(){
    fast;
    int tt=1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        solve(i);
    }
    return 0;
}
