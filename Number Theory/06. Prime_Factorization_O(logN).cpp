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


void initIO() {
fast;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
//O(log power)
const int MAX=1e6+5;
//array for Smallest Prime Factor Store
int ara[MAX];
//GeeksforGeeks
void seive(int n){
    /* marking smallest prime factor for every
     number by itself.*/
    for(int i=1;i<=n;i++) ara[i]=i;
    //all even smallest prime factor is 2
    for(int i=4;i<=n;i+=2) ara[i]=2;

    //run loop for only odds
    for(int i=3;i*i<=n;i+=2){
        //check prime or not
        if(ara[i]==i){
            for(int j=i*i;j<=n;j+=(i*2)){
                // marking ara[j] if it is not
                // previously marked
                if (ara[j]==j) ara[j]=i;
            }
        }
    }
}
vector<int> primeFactorization(int n){
    vector<int> pf;
    while(n>1){
        pf.push_back(ara[n]);
        n=n/ara[n];
    }
    return pf;
}
void solve() {
    //SOLVE PROBLEM HER
    int q;cin>>q;
    while(q--){
        int n;cin>>n;
        vector<int> a=primeFactorization(n);
        for(int i=0;i<a.size();i++)
            cout<<a[i]<<" ";
        cout<<nline;
    }
}


int main()
{
    seive(1e6);
    //initIO();
    fast;
    solve();
    cout<<"H";
    return 0;
}

