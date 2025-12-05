class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int i:nums)sum+=i;
        int n=nums.size();
        if(sum%2==1){
            return 0;
        }
        return n-1;
    }
};