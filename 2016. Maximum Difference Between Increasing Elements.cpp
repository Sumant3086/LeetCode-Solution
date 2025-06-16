// 2016. Maximum Difference Between Increasing Elements
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

// Return the maximum difference. If no such i and j exists, return -1.

 

// Example 1:

// Input: nums = [7,1,5,4]
// Output: 4
// Explanation:
// The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
// Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
// Example 2:

// Input: nums = [9,4,3,2]
// Output: -1
// Explanation:
// There is no i and j such that i < j and nums[i] < nums[j].
// Example 3:

// Input: nums = [1,5,2,10]
// Output: 9
// Explanation:
// The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.
 

// Constraints:

// n == nums.length
// 2 <= n <= 1000
// 1 <= nums[i] <= 109

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 165,110/262.5K
// Acceptance Rate
// 62.9%
// Topics
// Array
// icon
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (93)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int res=-1;
        int mini=nums[0];
        for(int i:nums){
            if(i>mini){
                res=max(res,i-mini);
            }
            mini=min(mini,i);
        }
        return res;
    }
};