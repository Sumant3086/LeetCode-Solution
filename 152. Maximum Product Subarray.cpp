// 152. Maximum Product Subarray
// Solved
// Medium
// Topics
// Companies
// Given an integer array nums, find a 
// subarray
//  that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 1.5M
// Submissions
// 4.4M
// Acceptance Rate
// 34.4%
// Topics
// Array
// Dynamic Programming
// Companies
// Similar Questions
// Discussion (250)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

// 19.1K


// 250





class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax=nums[0];
        int currMin=nums[0];
        int totM=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            int temp=max({nums[i],currMax*nums[i],currMin*nums[i]});
            currMin=min({nums[i],currMax*nums[i],currMin*nums[i]});
            currMax=temp;   
            totM=max(totM,currMax);
        }
        return totM;
    }
};