// 2554. Maximum Number of Integers to Choose From a Range I
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

// The chosen integers have to be in the range [1, n].
// Each integer can be chosen at most once.
// The chosen integers should not be in the array banned.
// The sum of the chosen integers should not exceed maxSum.
// Return the maximum number of integers you can choose following the mentioned rules.

 

// Example 1:

// Input: banned = [1,6,5], n = 5, maxSum = 6
// Output: 2
// Explanation: You can choose the integers 2 and 4.
// 2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
// Example 2:

// Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
// Output: 0
// Explanation: You cannot choose any integer while following the mentioned conditions.
// Example 3:

// Input: banned = [11], n = 7, maxSum = 50
// Output: 7
// Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
// They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.
 

// Constraints:

// 1 <= banned.length <= 104
// 1 <= banned[i], n <= 104
// 1 <= maxSum <= 109

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 78.5K
// Submissions
// 123.4K
// Acceptance Rate
// 63.6%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Similar Questions
// Discussion (108)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

// 531


// 108





class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, int> mp;
        for (int i : banned) {
            mp[i]++;
        }
        int sum = 0, res = 0;
        for (int i = 1; i <= n; i++) {
            if (!mp[i]) {
                sum += i;
                if (sum <= maxSum) {
                    res++;
                } else {
                    return res;
                }
            }
        }
        return res;
    }
};