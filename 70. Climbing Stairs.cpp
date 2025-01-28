// 70. Climbing Stairs
// Solved
// Easy
// Topics
// Companies
// Hint
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
 

// Constraints:

// 1 <= n <= 45
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 3.9M
// Submissions
// 7.3M
// Acceptance Rate
// 53.3%
// Topics
// Math
// Dynamic Programming
// Memoization
// Companies
// Hint 1
// Similar Questions
// Discussion (414)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
public:
    int helper(int n,vector<int>&dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
            return dp[n]=helper(n-1,dp)+helper(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};

// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n==0 || n==1){
//             return 1;
//         }
//         return climbStairs(n-1)+climbStairs(n-2);
//     }
// };
