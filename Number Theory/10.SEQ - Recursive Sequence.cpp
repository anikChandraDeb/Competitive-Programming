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

#define pb push_back
#define lcm(a,b) (a*b)/__gcd(a,b)
#define all(v) v.begin(),v.end()
char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
const int MAX = 2e5+5;
const int INF = INT_MAX;
#define m 1000000000
void initIO() {
fast;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}


lli ar[11],I[11][11],T[11][11],C[11];
lli n,k;

void multiply(lli A[][11],lli B[][11],int dim){
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
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++)
            if(i==j) I[i][j]=1;
            else I[i][j]=0;
    }

    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++) T[i][j]=0;
    }
    for(int i=1;i<=k;i++) T[i][k]=C[k-i+1];
    for(int i=2,j=1;i<=k && j<=k;i++,j++) T[i][j]=1;

    if(n<=k) return ar[n];
    n--;
    while(n){
        if(n%2) multiply(I,T,k),n--;
        else multiply(T,T,k),n/=2;
    }
    //lli fn=((ar[1]*I[1][1])%m+(ar[2]*I[2][1])%m+(ar[3]*I[3][1])%m)%m;
    lli fn=0LL;
    for(int i=1;i<=k;i++){
        fn=(fn%m+(ar[i]*I[i][1])%m)%m;
    }
    return fn%m;
}
void solve(){
    cin>>k;
    for(int i=1;i<=k;i++) cin>>ar[i];
    for(int i=1;i<=k;i++) cin>>C[i];
    cin>>n;
    cout<<getFn(k,n)<<nline;
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
