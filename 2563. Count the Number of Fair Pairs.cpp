// 2563. Count the Number of Fair Pairs
// Solved
// Medium
// Topics
// Companies
// Hint
// Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

// A pair (i, j) is fair if:

// 0 <= i < j < n, and
// lower <= nums[i] + nums[j] <= upper
 

// Example 1:

// Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
// Output: 6
// Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
// Example 2:

// Input: nums = [1,7,9,2,5], lower = 11, upper = 11
// Output: 1
// Explanation: There is a single fair pair: (2,3).
 

// Constraints:

// 1 <= nums.length <= 105
// nums.length == n
// -109 <= nums[i] <= 109
// -109 <= lower <= upper <= 109

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 122.5K
// Submissions
// 250.7K
// Acceptance Rate
// 48.9%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Similar Questions
// Discussion (171)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

// 1.5K


// 171





class Solution {
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        long long ans = 0;
        sort(v.begin(), v.end());

        for (int i = 0; i < v.size() - 1; i++) {
            auto up = upper_bound(v.begin() + i + 1, v.end(), upper - v[i]);
            auto low = lower_bound(v.begin() + i + 1, v.end(), lower - v[i]);
            ans += (up - low);
        }
        return ans;
    }
};