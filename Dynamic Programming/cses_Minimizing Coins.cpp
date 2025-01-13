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
int way(int x,vector<int> &coin){
    if(x==0) return 0;
    if(dp[x]!=-1) return dp[x];
    int ans=INT_MAX;
    for(auto c:coin){
        if((x-c)>=0)
            ans=min(ans+0LL,way(x-c,coin)+1LL);
    }
    return dp[x]=ans;
}
//O(x*n) x=10^6 and n=100
void solve(){
    int x,n;
    cin>>n>>x;
    vector<int> coin(n);inv(n);
//    for(int i=0;i<(1<<6);i++){
//        int sum=0;
//        for(int j=0;j<6;j++){
//            if(i & (1<<j)) sum=sum*10+1;
//            else sum*=10;
//        }
//        if(sum <= x && sum!=0) coin.push_back(sum);
//    }
//    sort(coin.begin(),coin.end());
    int ans=way(x,coin);
    cout<<ans<<nline;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    solve();
    return 0;
}
