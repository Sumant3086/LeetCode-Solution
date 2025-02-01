// 3151. Special Array I
// Solved
// Easy
// Topics
// Companies
// Hint
// An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

// You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

 

// Example 1:

// Input: nums = [1]

// Output: true

// Explanation:

// There is only one element. So the answer is true.

// Example 2:

// Input: nums = [2,1,4]

// Output: true

// Explanation:

// There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.

// Example 3:

// Input: nums = [4,3,1,6]

// Output: false

// Explanation:

// nums[1] and nums[2] are both odd. So the answer is false.

 

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 168.8K
// Submissions
// 207K
// Acceptance Rate
// 81.6%
// Topics
// Array
// Companies
// Hint 1
// Discussion (181)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return true;
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]%2==nums[i+1]%2){
                return false;
            }
        }
        return true;
    }
};