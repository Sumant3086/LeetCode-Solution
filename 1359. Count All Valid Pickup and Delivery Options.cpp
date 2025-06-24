// 1359. Count All Valid Pickup and Delivery Options
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given n orders, each order consists of a pickup and a delivery service.

// Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

// Since the answer may be too large, return it modulo 10^9 + 7.

 

// Example 1:

// Input: n = 1
// Output: 1
// Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
// Example 2:

// Input: n = 2
// Output: 6
// Explanation: All possible orders: 
// (P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
// This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
// Example 3:

// Input: n = 3
// Output: 90
 

// Constraints:

// 1 <= n <= 500

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 130,294/200.9K
// Acceptance Rate
// 64.9%
// Topics
// icon
// Companies
// Hint 1
// Use the permutation and combination theory to add one (P, D) pair each time until n pairs.
// Discussion (68)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.

class Solution {
public:
    int countOrders(int n) {
        int mod=1e9+7;
        long long res=1;
        for(int i=1;i<=n;i++){
            res*=(2*i-1)%mod;
            res=(res*i)%mod;
        }
        return res;
    }
};