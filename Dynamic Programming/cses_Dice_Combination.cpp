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
#define vll vector<lli>
#define vc vector<char>
#define mod 1000000007

const int MAX = 1e6 + 5;
lli dp[MAX];
lli way(int n,vector<int> &dice){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    lli ans=0;
    for(auto c:dice){
        if((n-c)>=0)
            ans=(ans+way(n-c,dice))%mod;
    }
    return dp[n]=ans;
}
//O(n*dice) n around 10^7
void solve(){
    int n;
    vector<int> dice{1,2,3,4,5,6};
    cin>>n;
    cout<<way(n,dice)<<nline;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    solve();
    return 0;
}
