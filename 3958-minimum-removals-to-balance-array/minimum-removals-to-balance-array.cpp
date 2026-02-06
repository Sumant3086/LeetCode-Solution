class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int rem=0;
        int n=nums.size();
        int l=0;
        for(int r=0;r<n;r++){ 
            if(1LL*nums[r]>1LL*nums[l]*k){
                l++;
            }
            rem=max(rem,r-l+1);
        }
        return n-rem;
    }
};