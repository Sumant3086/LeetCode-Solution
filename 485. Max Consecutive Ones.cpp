// 485. Max Consecutive Ones
// Solved
// Easy
// Topics
// Companies
// Hint
// Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

// Example 1:

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
// Example 2:

// Input: nums = [1,0,1,1,0,1]
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 1.5M
// Submissions
// 2.4M
// Acceptance Rate
// 61.4%
// Topics
// Companies
// Hint 1
// Similar Questions
// Discussion (60)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int maxOnes=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
            }else{
                count=0;
            }
            maxOnes=max(maxOnes,count);
        }
        return maxOnes;
    }
};