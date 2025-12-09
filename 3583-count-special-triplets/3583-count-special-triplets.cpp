class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD=1e9+7LL; 
        unordered_map<int,long long>right;
        unordered_map<int,long long>left;
        for(int i:nums)right[i]++;
        long long res=0;
        for(int j:nums){
            // int x=nums[j];
            right[j]--;
            int tar=j*2;
            if(tar<=200000){
                res=(res+left[tar]*right[tar])%MOD;
            }
            left[j]++;
        }
        return (int)res;
    }
};


// class Solution {
// public:
//     int specialTriplets(vector<int>& nums) {
//         const int MOD=1e9+7;
//         static long long right[200001]={0},left[200001]={0};
//         for(int i:nums)right[i]++;
//         long long res=0;
//         for(int j=0;j<nums.size();j++){
//             int x=nums[j];
//             right[x]--;
//             int tar=x*2;
//             if(tar<=200000){
//                 res=(res+left[tar]*right[tar])%MOD;
//             }
//             left[x]++;
//         }
//         return res;
//     }
// };
