// 78. Subsets
// Solved
// Medium
// Topics
// Companies
// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n=nums.size();
//         int mask=1<<n;
//         vector<vector<int>>powerSet(mask);
//         for(int j=0;j<mask;j++){
//             for(int i=0;i<n;i++){
//                 if(j& 1<<i){
//                     powerSet[j].push_back(nums[i]);
//                 }
//             }
//         }
//         return powerSet;
//     }
// };


class Solution {
public:
    void generate(vector<int>& nums,int idx,vector<int>& curr,vector<vector<int>>& ans){
        if(idx>=nums.size()){
            ans.push_back(curr);
            return ;
        }
        curr.push_back(nums[idx]);
        generate(nums,idx+1,curr,ans);
        curr.pop_back();
        generate(nums,idx+1,curr,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>curr;
        generate(nums,0,curr,ans);
        return ans;
    }
};