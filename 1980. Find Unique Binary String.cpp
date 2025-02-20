// 1980. Find Unique Binary String
// Medium
// Topics
// Companies
// Hint
// Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

// Example 1:

// Input: nums = ["01","10"]
// Output: "11"
// Explanation: "11" does not appear in nums. "00" would also be correct.
// Example 2:

// Input: nums = ["00","01"]
// Output: "11"
// Explanation: "11" does not appear in nums. "10" would also be correct.
// Example 3:

// Input: nums = ["111","011","001"]
// Output: "101"
// Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

// Constraints:

// n == nums.length
// 1 <= n <= 16
// nums[i].length == n
// nums[i] is either '0' or '1'.
// All the strings of nums are unique.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 243.8K
// Submissions
// 310.7K
// Acceptance Rate
// 78.5%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (192)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

// 2.4K


// 192





class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            string res;
            for(int i=0;i<nums.size();i++){
                if(nums[i][i]=='0'){
                    res+='1';
                }else{
                    res+='0';
                }
            }
            return res;
        }
    };