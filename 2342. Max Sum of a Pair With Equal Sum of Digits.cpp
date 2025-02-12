// 2342. Max Sum of a Pair With Equal Sum of Digits
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

// Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

 

// Example 1:

// Input: nums = [18,43,36,13,7]
// Output: 54
// Explanation: The pairs (i, j) that satisfy the conditions are:
// - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
// - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
// So the maximum sum that we can obtain is 54.
// Example 2:

// Input: nums = [10,12,19,14]
// Output: -1
// Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 160.6K
// Submissions
// 249.8K
// Acceptance Rate
// 64.3%
// Topics
// Companies
// Hint 1
// Hint 2
// Discussion (179)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap; 
        int maxSum = -1;

        for (int num : nums) {
            int sumDigits = getDigitSum(num);
            if (digitSumMap.count(sumDigits)) {
                maxSum = max(maxSum, digitSumMap[sumDigits] + num);
                digitSumMap[sumDigits] = max(digitSumMap[sumDigits], num);
            } else {
                digitSumMap[sumDigits] = num;
            }
        }
        return maxSum;
    }

private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
