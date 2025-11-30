class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int totSum=0;
        for(int num:nums){
            totSum=(totSum+num)%p;
        }
        int target=totSum%p;
        if(target==0)return 0;
        unordered_map<int,int>mod;
        mod[0]=-1;
        int currSum=0,minLen=n;
        for(int i=0;i<n;i++){
            currSum=(currSum+nums[i])%p;
            int need=(currSum-target+p)%p;
            if(mod.find(need)!=mod.end()){
                minLen=min(minLen,i-mod[need]);
            }
            mod[currSum]=i;
        }
        return minLen==n?-1:minLen;
    }
};