// 1752. Check if Array Is Sorted and Rotated
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

 

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
// Example 2:

// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.
// Example 3:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.
// You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 457.6K
// Submissions
// 854.9K
// Acceptance Rate
// 53.5%
// Topics
// Companies
// Hint 1
// Similar Questions
// Discussion (247)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int peak=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                peak++;
            }
            if(peak>1){
                return false;
            }
        }
        return true;
    }
};