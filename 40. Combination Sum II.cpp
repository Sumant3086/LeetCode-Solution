// 40. Combination Sum II
// Solved
// Medium
// Topics
// Companies
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
 

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30


// class Solution {
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end());
//         vector<vector<int>>res;
//         vector<int>combination;
//         combination2(res,combination,candidates,target,0);
//         return res;
//     }
//     void combination2(vector<vector<int>>&result,vector<int>& combination,vector<int>& candidates,int target,int idx){
//         if(target==0){
//             result.push_back(combination);
//             return;
//         }
//         for(int i=idx;i<candidates.size( ) && target>=candidates[i];i++){
//             if(i==idx || candidates[i]!=candidates[i-1]){
//                 combination.push_back(candidates[i]);
//                 combination2(result,combination,candidates,target-candidates[i],i+1);
//                 combination.pop_back();
//             }
//         }
//     }
// };

class Solution {
public:
    void solve(vector<int>& candidates, int &sum, vector<vector<int>> &     output, vector<int> &ans, int i, int target){

	if(sum==target){
        output.push_back(ans);
        return;
    }

    if(i>=candidates.size() || sum+candidates[i]>target)
        return;

    sum+=candidates[i];
    ans.push_back(candidates[i]);
    solve(candidates, sum, output, ans, i+1, target);
    ans.pop_back();
    sum-=candidates[i];
    while(i+1<candidates.size() && candidates[i]==candidates[i+1] )
        i++;
    solve(candidates, sum, output, ans, i+1, target);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)    {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> output;
        vector<int> ans;
        int sum=0;
	    solve(candidates, sum,  output,  ans,  0, target);
	    return output;
    }
};