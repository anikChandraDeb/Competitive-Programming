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
#define vc vector<char>
#define p32 pair<int,int>
#define p64 pair<lli,lli>
#define caseOP(t,o) cout<<"Case "<<t<<": "<<o
#define caseOPi(t,o) printf("Case %d: %d\n",t,o)
#define caseOPl(t,o) printf("Case %d: %lld\n",t,o)
#define caseOPd(t,o) printf("Case %d: %lf\n",t,o)
#define mod 1000000007
#define pb push_back
#define lcm(a,b) (a*b)/__gcd(a,b)
#define all(v) v.begin(),v.end()
char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
const int MAX = 2e5+5;
const int INF = INT_MAX;

void initIO() {
fast;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
lli module(lli a){
    if(a<0) return (a+2*mod)%mod;
    else return a%mod;
}

lli ar[4],I[4][4],T[4][4];
lli a,b,c,n,m;

void multiply(lli A[4][4],lli B[4][4],int dim){
    lli res[dim+1][dim+1];

    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++){
            res[i][j]=0;
            for(int k=1;k<=dim;k++){
                res[i][j]=(res[i][j]%m+(A[i][k]%m*B[k][j]%m)%m)%m;
            }
        }
    }
    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++){
            A[i][j]=res[i][j];
        }
    }
}
lli getFn(int dim,int n){
    for(int i=1;i<4;i++){
        for(int j=1;j<4;j++)
            if(i==j) I[i][j]=1;
            else I[i][j]=0;
    }

    T[1][1]=0;
    T[1][2]=b;
    T[1][3]=0;
    T[2][1]=1;
    T[2][2]=a;
    T[2][3]=0;
    T[3][1]=0;
    T[3][2]=c;
    T[3][3]=1;
    if(n<=2) return ar[n];
    n--;
    while(n){
        if(n%2) multiply(I,T,3),n--;
        else multiply(T,T,3),n/=2;
    }
    lli fn=((ar[1]*I[1][1])%m+(ar[2]*I[2][1])%m+(I[3][1]*1)%m)%m;
    //fn=(fn%m+((n-2)%m*c%m)%m)%m;
    return fn;
}
void solve(){
    cin>>a>>b>>c>>n>>m;
    ar[1]=1;
    ar[2]=1;

    cout<<getFn(2,n)<<nline;

}

int main()
{
    //initIO();
    fast;
    int tt=1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        solve();
    }
    return 0;
}
