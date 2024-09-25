#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
int Prime[MAX],nPrime;
bool mark[MAX]={0};

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
    seive(9999);
    cout<<nPrime<<endl;
    for(int i=0;i<nPrime;i++) cout<<Prime[i]<<" ";
    cout<<mark[2]<<endl;
    return 0;
}
