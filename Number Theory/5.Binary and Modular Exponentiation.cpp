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
//O(log power)
int power(int a,int b){
    int res=1;
    while(b){
        if(b%2)
            res*=a,b--;
        else
            a*=a,b/=2;
    }
    return res;
}
int powerMod(int a,int b,int m){
    int res=1;
    while(b){
        if(b%2)
            res=(res*a)%m,b--;
        else
            a=(a*a)%m,b/=2;
    }
    return res;
}
void solve() {
    //SOLVE PROBLEM HER
    int a,b;
    cin>>a>>b;
    cout<<power(a,b)<<nline;
    cout<<powerMod(a,b,2)<<nline;
}


int main()
{

    solve();
    return 0;
}

