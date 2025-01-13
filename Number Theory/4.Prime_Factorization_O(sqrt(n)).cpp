/*Anik Deb -> CSE,DUET*/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
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

const int MAX = 1e5 + 5;
void initIO() {
fast;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
//O(N)
void primeFactorization1(int N){
    for(int i=2;i<=N;i++){
        if(N%i==0){
            int cnt=0;
            while(N%i==0)
                cnt++,N/=i;
            cout<<i<<"^"<<cnt<<nline;
        }
    }
}
//O(sqrt(n))
void primeFactorization2(int N){
    for(int i=2;i*i<=N;i++){
        if(N%i==0){
            int cnt=0;
            while(N%i==0)
                cnt++,N/=i;
            cout<<i<<"^"<<cnt<<nline;
        }
    }
    if(N>1) cout<<N<<"^"<<1<<nline;
}
void solve() {
    //SOLVE PROBLEM HER
    int n;cin>>n;
    primeFactorization1(n);
    primeFactorization2(n);
}


int main()
{
    initIO();
    solve();
    return 0;
}

