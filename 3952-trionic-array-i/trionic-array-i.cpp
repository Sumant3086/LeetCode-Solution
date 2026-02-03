class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        if(n<4 || nums[0]>=nums[1])return false;
        int change=0;
        int way=1;
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i+1])return false;
            int nxtW=(nums[i]<nums[i+1])?1:-1;
            if(way!=nxtW){
                change++;
                way=nxtW;
            }
        } 
        return change==2;
    }
};