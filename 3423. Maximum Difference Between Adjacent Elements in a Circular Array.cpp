// 3423. Maximum Difference Between Adjacent Elements in a Circular Array
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a circular array nums, find the maximum absolute difference between adjacent elements.

// Note: In a circular array, the first and last elements are adjacent.

 

// Example 1:

// Input: nums = [1,2,4]

// Output: 3

// Explanation:

// Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.

// Example 2:

// Input: nums = [-5,-10,-5]

// Output: 5

// Explanation:

// The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.

 

// Constraints:

// 2 <= nums.length <= 100
// -100 <= nums[i] <= 100

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 55,448/77.9K
// Acceptance Rate
// 71.1%
// Topics
// icon
// Companies
// Hint 1
// Hint 2
// Discussion (48)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,abs(nums[i]-nums[(i+1)%n]));
        }
        return maxi;
    }
};