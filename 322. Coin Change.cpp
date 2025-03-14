// 322. Coin Change
// Medium
// Topics
// Companies
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
 

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 2.2M
// Submissions
// 4.8M
// Acceptance Rate
// 45.9%
// Topics
// Companies
// Similar Questions
// Discussion (158)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            vector<int>dp(amount+1,amount+1);
            dp[0]=0;
            for(int coin:coins){
                for(int j=coin;j<=amount;j++){
                    dp[j]=min(dp[j],dp[j-coin]+1);
                }
            }
            return dp[amount]==amount+1?-1:dp[amount];
        }
    };