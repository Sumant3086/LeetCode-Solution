// 46. Permutations
// Solved
// Medium
// Topics
// Companies
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.

class Solution {
public:
   void fn(int i, vector<int>&a,vector<vector<int>>&ans){
    if(i==a.size()){
        ans.push_back(a);return;
    }
    for(int j=i;j<a.size();j++){
        swap(a[i],a[j]);
        fn(i+1,a,ans);
        swap(a[i],a[j]);// backtrack
    }
}
    vector<vector<int>> permute(vector<int>& a) {
       vector<vector<int>>ans;
       fn(0,a,ans);
        return ans;
    }
};