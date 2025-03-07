// 2681. Power of Heroes
// Solved
// Hard
// Topics
// Companies
// Hint
// You are given a 0-indexed integer array nums representing the strength of some heroes. The power of a group of heroes is defined as follows:

// Let i0, i1, ... ,ik be the indices of the heroes in a group. Then, the power of this group is max(nums[i0], nums[i1], ... ,nums[ik])2 * min(nums[i0], nums[i1], ... ,nums[ik]).
// Return the sum of the power of all non-empty groups of heroes possible. Since the sum could be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [2,1,4]
// Output: 141
// Explanation: 
// 1st group: [2] has power = 22 * 2 = 8.
// 2nd group: [1] has power = 12 * 1 = 1. 
// 3rd group: [4] has power = 42 * 4 = 64. 
// 4th group: [2,1] has power = 22 * 1 = 4. 
// 5th group: [2,4] has power = 42 * 2 = 32. 
// 6th group: [1,4] has power = 42 * 1 = 16. 
// ​​​​​​​7th group: [2,1,4] has power = 42​​​​​​​ * 1 = 16. 
// The sum of powers of all groups is 8 + 1 + 64 + 4 + 32 + 16 + 16 = 141.

// Example 2:

// Input: nums = [1,1,1]
// Output: 7
// Explanation: A total of 7 groups are possible, and the power of each group will be 1. Therefore, the sum of the powers of all groups is 7.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 10.4K
// Submissions
// 33.6K
// Acceptance Rate
// 31.1%
// Topics
// Array
// Math
// Dynamic Programming
// Sorting
// Prefix Sum
// Companies
// Hint 1
// Hint 2
// Hint 3
// Hint 4
// Discussion (15)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
    public:
        int sumOfPower(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            long long ans=0;
            long long mod=1e9+7;
            long long sum=0;
            for(long long i:nums){
                ans=(ans+(i*i%mod)*(i+sum)%mod)%mod;
                sum=(sum*2+i)%mod;
            }
            return ans;
        }
    };