class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1)return 0;
        int minD=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i+k-1<nums.size();i++){
            minD=min(minD,nums[i+k-1]-nums[i]);
        }
        return minD;
    }
};