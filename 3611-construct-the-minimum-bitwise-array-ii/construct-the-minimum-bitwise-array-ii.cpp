class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==2){
                res.push_back(-1);
            }else{
                int bit=0;
                while((nums[i]>>bit) & 1){
                    bit++;
                }
                res.push_back(nums[i]-(1<<(bit-1)));
            }
        }
        return res;
    }
};             