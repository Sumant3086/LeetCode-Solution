// 2466. Count Ways To Build Good Strings
// Medium
// Topics
// Companies
// Hint
// Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

// Append the character '0' zero times.
// Append the character '1' one times.
// This can be performed any number of times.

// A good string is a string constructed by the above process having a length between low and high (inclusive).

// Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

 

// Example 1:

// Input: low = 3, high = 3, zero = 1, one = 1
// Output: 8
// Explanation: 
// One possible valid good string is "011". 
// It can be constructed as follows: "" -> "0" -> "01" -> "011". 
// All binary strings from "000" to "111" are good strings in this example.
// Example 2:

// Input: low = 2, high = 3, zero = 1, one = 2
// Output: 5
// Explanation: The good strings are "00", "11", "000", "110", and "011".
 

// Constraints:

// 1 <= low <= high <= 105
// 1 <= zero, one <= low
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 95.6K
// Submissions
// 171.3K
// Acceptance Rate
// 55.8%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (100)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

// 1.8K


// 100





const int mod=1e9+7;
int dp[100001];
class Solution {
public:
    static int good(int n, int x0, int x1){
        if ( dp[n]!=-1 ) return dp[n];
        long long ans;
        if (n <= x0)//base case
            ans=1;
        
        if ( n >= x0)
            ans+=good(n-x0, x0, x1);
        
        if ( n >= x1)
            ans+=good(n-x1, x0, x1);
        
        return dp[n]=ans%mod;
    }
    static int countGoodStrings(int low, int high, int zero, int one) {
        if (zero > one) swap(zero, one);
        fill(dp, dp+high+1, -1);
        return (good(high, zero, one)-good(low-1, zero, one)+mod)%mod;
    }
};