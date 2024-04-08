class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int left=0;
        int right=0;
        int result=0;
        unordered_map<int,int>map;
        while(left<nums.size() && right<nums.size()){
            map[nums[right]]++;
            while(map[nums[right]]>k){
                map[nums[left]]--;
                left++;
            }
            result=max(result,right-left+1);
            right++;
        }
        return result;
    }
};