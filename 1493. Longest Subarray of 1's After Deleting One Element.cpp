// 1493. Longest Subarray of 1's After Deleting One Element
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
// Example 3:

// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 519,821/738.8K
// Acceptance Rate
// 70.4%
// Topics
// icon
// Companies
// Hint 1
// Similar Questions
// Discussion (187)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.

// 4.5K


// 187



class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0,zero=0,ans=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0)zero++;
            while(zero>1){
                if(nums[left]==0)zero--;
                left++;
                
            }
            ans=max(ans,right-left);
        }
        return ans;
    }
};