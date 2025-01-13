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
#define caseOP(t,o) cout<<"Case "<<t<<": "<<o
#define caseOPi(t,o) printf("Case %d: %d\n",t,o)
#define caseOPl(t,o) printf("Case %d: %lld\n",t,o)
#define caseOPd(t,o) printf("Case %d: %lf\n",t,o)
#define mod 998244353
#define pb push_back
#define lcm(a,b) (a*b)/__gcd(a,b)
#define all(v) v.begin(),v.end()
char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pbds tree<lli, null_type, less<lli>,rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
*/

const int MAX = 1e5+5;
const int MAX1 = 2e5+5;
const int INF = INT_MAX;

int pre[MAX],suff[MAX];

int gcd(int a,int b){
    if(b==0) return a;
    else gcd(b,a%b);
}

void solve(){
    int n,q;cin>>n>>q;
    vi a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    pre[0]=suff[n+1]=0;
    for(int i=1;i<=n;i++) pre[i]=gcd(a[i],pre[i-1]);
    for(int i=n;i>=1;i--) suff[i]=gcd(a[i],suff[i+1]);
    while(q--){
        int l,r;cin>>l>>r;
        cout<<__gcd(pre[l-1],suff[r+1])<<nline;
    }
}


int main()
{
    fast;
    int tt=1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        solve();
    }
    return 0;
}
