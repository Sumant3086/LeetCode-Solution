class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(int i:nums)sum+=i;
        int rem=sum%k;
        if(rem==0)return 0;
        return rem;
    }
};