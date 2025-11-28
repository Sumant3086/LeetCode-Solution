class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>minP(k,LLONG_MAX);
        long long res=-LLONG_MAX,pref=0;
        minP[0]=0;
        for(int i=0;i<n;i++){
            pref+=nums[i];
            int r=(i+1)%k;
            if(minP[r]!=LLONG_MAX){
                res=max(res,pref-minP[r]);
            }
            minP[r]=min(minP[r],pref);
        }
        return res;
    }
};