#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
using namespace std;
const int MAX=1e6+5;
vector<lli> primes;
bool mark[MAX]={0};

void seive(int n){
    int limit=sqrt(n)+2;
    mark[1]=1;
    //all even are not prime
    for(int i=4;i<=n;i+=2) mark[i]=1;
    primes.pb(2);

    //run loop for only odds
    for(int i=3;i<=n;i+=2){
        if(!mark[i]){
            primes.pb(i);
            if(i<=limit){
                for(int j=i*i;j<=n;j+=(i*2)){
                    mark[j]=1;
                }
            }
        }

    }
}

bool isPrime[1000005];

void segSieve (lli l, lli r) {

    for (int i = 0; i < r - l + 1; ++i) isPrime[i] = true;
    if (l == 1) isPrime[0] = false;
    //all prime less then ar equal to p<=sqrt(r) so primes[i]*primes[i]<=r
    for (int i = 0; primes[i]*primes[i] <= r; ++i) {
        int currentPrime = primes[i];
        lli base = (l/currentPrime)*currentPrime;
        if (base < l) base += currentPrime;
        for (lli j = base; j <= r; j += currentPrime) {
            isPrime[j-l] = false;
        }
        if (base == currentPrime) isPrime[base-l] = true;
    }
    for (int i = 0; i < r - l + 1; ++i) {
        if (isPrime[i]) cout << (i+l) << endl;
    }
    cout<<" "<<nline;
}
int main()
{
    seive(1000000);
    int q;cin>>q;
    while(q--){
        lli l,r;cin>>l>>r;
        segSieve(l,r); //if we need to check a big number is prime or not then pre-calculate segSieve
    }
    return 0;
}
