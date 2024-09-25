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
const int MAX1 = 5000000+1;
const int MAX2=1e8+5;
int Prime[MAX1],nPrime;
bool mark[MAX2]={0};

void seive(int n){
    int limit=sqrt(n)+2;
    nPrime=0;
    mark[1]=1;
    //all even are not prime
    for(int i=4;i<=n;i+=2) mark[i]=1;
    Prime[nPrime++]=2;

    //run loop for only odds
    for(int i=3;i<=n;i+=2){
        if(!mark[i]){
            Prime[nPrime++]=i;
            if(nPrime>=5000000) break;
            if(i<=limit){
                for(int j=i*i;j<=n;j+=(i*2)){
                    mark[j]=1;
                }
            }
        }

    }
}

int main()
{
    seive(1e8);
    cout<<sizeof(bool)<<nline;
    int q;cin>>q;
    while(q--){
        int k;cin>>k;
        cout<<Prime[k-1]<<nline;
    }
    return 0;
}
