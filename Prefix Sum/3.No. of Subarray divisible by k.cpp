#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k){
        map<lli,int> mp;
        mp[0]=1;
        lli sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            lli r=sum%k;
            if(r<0) r=(r+k)%k;
            mp[r]++;
            if(mp[r]>1) {
                ans+=mp[r]-1;
            }
        }
        return ans;
    }
};
