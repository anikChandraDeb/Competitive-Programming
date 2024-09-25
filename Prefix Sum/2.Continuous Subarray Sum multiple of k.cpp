#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<lli,int> mp;
        mp[0]=-1;
        lli sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum%k)==mp.end()){
                mp[sum%k]=i;
            }
            else{
                if(i-mp[sum%k]>=2) return 1;
            }
        }
        return 0;
    }
};
