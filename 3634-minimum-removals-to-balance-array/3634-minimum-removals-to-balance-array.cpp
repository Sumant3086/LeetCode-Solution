class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int keep=0;
        int n=nums.size();
        int l=0;
        for(int r=0;r<n;r++){ 
            if(1LL*nums[r]>1LL*nums[l]*k){
                l++;
            }
            keep=max(keep,r-l+1);
        }
        return n-keep;
    }
};