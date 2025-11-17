// 1437. Check If All 1's Are at Least Length K Places Away
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.

 

// Example 1:


// Input: nums = [1,0,0,0,1,0,0,1], k = 2
// Output: true
// Explanation: Each of the 1s are at least 2 places away from each other.
// Example 2:


// Input: nums = [1,0,0,1,0,1], k = 2
// Output: false
// Explanation: The second 1 and third 1 are only one apart from each other.
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= k <= nums.length
// nums[i] is 0 or 1
 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 141,215/227K
// Acceptance Rate
// 62.2%
// Topics
// icon
// Companies
// Hint 1
// Similar Questions
// Discussion (62)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.


class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                if(last!=-1 && i-last-1<k)return false;
                last=i;
            }
        }
        return true;
    }
};