// 47. Permutations II
// Solved
// Medium
// Topics
// Companies
// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// Example 2:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

// Constraints:

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 1M
// Submissions
// 1.7M
// Acceptance Rate
// 60.6%
// Topics
// Companies
// Similar Questions
// Discussion (42)

class Solution {
public:
void backtrack(vector<int>& nums,vector<vector<int>>& res, vector<int>& curr,vector<bool>& visited){
    if(curr.size()==nums.size()){
        res.push_back(curr);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(visited[i] || (i>0 && nums[i]==nums[i-1] && !visited[i-1])){
            continue;
        }
        visited[i]=true;
        curr.push_back(nums[i]);
        backtrack(nums,res,curr,visited);
        visited[i]=false;
        curr.pop_back();
    }
}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>curr;
        vector<bool>visited(nums.size(),false);
        backtrack(nums,res,curr,visited);
        return res;
    }
};