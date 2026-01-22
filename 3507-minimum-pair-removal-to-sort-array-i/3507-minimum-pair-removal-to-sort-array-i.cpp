class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops=0; 
        while(!is_sorted(nums.begin(),nums.end())){
            int minS=INT_MAX;
            int idx=-1; 
            for(int i=0;i<nums.size()-1;++i){
                int currS=nums[i]+nums[i+1];
                if(currS<minS){
                    minS=currS;
                    idx=i;
                }
            } 
            nums[idx]=minS;
            nums.erase(nums.begin()+idx+1);
            ops++;
        }
        return ops;
    }
};