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
const int MAX = 2e5+5;
const int INF = INT_MAX;
int ara[MAX];
struct node{
    int min,mincnt;
}segtree[MAX*4];
struct node INf;
void build(int nodeNum,int segs,int sege){
    if(segs==sege){ //base case when segment lenth one the result of the segment is this element
        segtree[nodeNum].min=ara[segs];
        segtree[nodeNum].mincnt=1;
        return;
    }
    int mid=(segs+sege)/2;
    build(nodeNum*2,segs,mid);
    build(nodeNum*2+1,mid+1,sege);
    segtree[nodeNum].min=min2(segtree[nodeNum*2].min,segtree[nodeNum*2+1].min);
    if(segtree[nodeNum*2].min==segtree[nodeNum*2+1].min) segtree[nodeNum].mincnt=segtree[nodeNum*2].mincnt+segtree[nodeNum*2+1].mincnt;
    else if(segtree[nodeNum].min==segtree[nodeNum*2].min) segtree[nodeNum].mincnt=segtree[nodeNum*2].mincnt;
    else  segtree[nodeNum].mincnt=segtree[nodeNum*2+1].mincnt;

     //segment tree for range minimum
    //segtree[nodeNum]=max(segtree[nodeNum*2],segtree[nodeNum*2+1]); segment tree for range maximum
    //segtree[nodeNum]=segtree[nodeNum*2]+segtree[nodeNum*2+1]; segment tree for range min

}
struct node query(int nodeNum,int segs,int sege,int qs,int qe){
    if(sege<qs || segs>qe) //completely outside ignore this segment
        return INf;
    if(segs>=qs && sege<=qe) //completely inside return result
        return segtree[nodeNum];
    //otherwise devide this segment by make recursion call
    int mid=(segs+sege)/2;
    struct node left=query(nodeNum*2,segs,mid,qs,qe);
    struct node right=query(nodeNum*2+1,mid+1,sege,qs,qe);
    struct node ans;
    ans.min=min2(left.min,right.min);
    if(left.min==right.min) ans.mincnt=left.mincnt+right.mincnt;
    else if(ans.min==left.min) ans.mincnt=left.mincnt;
    else ans.mincnt=right.mincnt;
    return ans;
}
//point update
void update(int nodeNum,int segs,int sege,int pos,int updateValue){
    if(sege<pos || segs>pos) //completely outside ignore this segment
        return;
    if(segs>=pos && sege<=pos) //completely inside return result
    {
        segtree[nodeNum].min=updateValue;
        segtree[nodeNum].mincnt=1;
        return;
    }
    //otherwise devide this segment by make recursion call
    int mid=(segs+sege)/2;
    update(nodeNum*2,segs,mid,pos,updateValue);
    update(nodeNum*2+1,mid+1,sege,pos,updateValue);
    segtree[nodeNum].min=min2(segtree[nodeNum*2].min,segtree[nodeNum*2+1].min);

    if(segtree[nodeNum*2].min==segtree[nodeNum*2+1].min) segtree[nodeNum].mincnt=segtree[nodeNum*2].mincnt+segtree[nodeNum*2+1].mincnt;
    else if(segtree[nodeNum].min==segtree[nodeNum*2].min) segtree[nodeNum].mincnt=segtree[nodeNum*2].mincnt;
    else  segtree[nodeNum].mincnt=segtree[nodeNum*2+1].mincnt;
}
void solve(){
    INf.min=INF;
    INf.mincnt=0;
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>ara[i];
    build(1,1,n);
//    for(int i=1;i<=2*n+1;i++) cout<<segtree[i].min<<" ";cout<<nline;
//    for(int i=1;i<=2*n+1;i++) cout<<segtree[i].mincnt<<" ";cout<<nline;
    for(int i=1;i<=q;i++){
        int l,r,t;
        cin>>t;
        if(t==2){
            cin>>l>>r;
            struct node result=query(1,1,n,l+1,r);
            cout<<result.min<<" "<<result.mincnt<<nline;
        }
        else{
            cin>>l>>r;
            update(1,1,n,l+1,r);
        }
//        for(int i=1;i<=2*n+1;i++) cout<<segtree[i].min<<" ";cout<<nline;
//        for(int i=1;i<=2*n+1;i++) cout<<segtree[i].mincnt<<" ";cout<<nline;
    }
}
int main()
{

    int tt=1;
    //cin>>tt;
    for(int i=1;i<=tt;i++){
        solve();
    }
    return 0;
}
