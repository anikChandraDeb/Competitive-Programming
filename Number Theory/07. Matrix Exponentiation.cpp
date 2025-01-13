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
const int MAX = 1e4+1;
int ar[MAX][MAX],I[MAX][MAX];
void multiply(int A[][MAX],int B[][MAX],int dim){
    int res[dim+1][dim+1];

    //Multiply matrix A*B
    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++){
            res[i][j]=0;
            for(int k=1;k<=dim;k++)
                res[i][j]=res[i][j]+(A[i][k]*B[k][j]);
        }
    }

    //store the result in A matrix
    for(int i=1;i<=dim;i++)
        for(int j=1;j<=dim;j++)
            A[i][j]=res[i][j];
}
void power(int A[][MAX],int dim,int n){
    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++){
            if(i==j) I[i][j]=1;
            else I[i][j]=0;
        }
    }
    //Complexity O(N) for calculating power
//    for(int i=1;i<=n;i++) //I=I*A
//        mul(I,A,dim);
    // usign binary exponentiation O(log N)
    while(n){
        if(n%2) multiply(I,A,dim),n--;
        else multiply(A,A,dim),n/=2;
    }

    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++)
            ar[i][j]=I[i][j];
    }
}
void printMat(int A[][MAX],int dim){
    for(int i=1;i<=dim;i++){
        for(int j=1;j<=dim;j++) cout<<A[i][j]<<" ";
        cout<<nline;
    }
}
void solve()
{
    int dim,n;
    cin>>dim>>n;
    for(int i=1;i<=dim;i++)
        for(int j=1;j<=dim;j++)
            cin>>ar[i][j];
    power(ar,dim,n);
    printMat(ar,dim);
}
int main()
{
    int tt=1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        solve();
    }
    return 0;
}
