// 1415. The k-th Lexicographical String of All Happy Strings of Length n
// Solved
// Medium
// Topics
// Companies
// Hint
// A happy string is a string that:

// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

// Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

// Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

 

// Example 1:

// Input: n = 1, k = 3
// Output: "c"
// Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
// Example 2:

// Input: n = 1, k = 4
// Output: ""
// Explanation: There are only 3 happy strings of length 1.
// Example 3:

// Input: n = 3, k = 9
// Output: "cab"
// Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
 

// Constraints:

// 1 <= n <= 10
// 1 <= k <= 100

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 134.6K
// Submissions
// 158.9K
// Acceptance Rate
// 84.7%
// Topics
// Companies
// Hint 1
// Hint 2
// Discussion (107)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
    int n2;
    string dfs(string prefix, int n, int k) {
        if (n == 0)
            return prefix;
        for (char c = 'a'; c <= 'c'; c++) {
            if (!prefix.empty() && c == prefix.back())
                continue;
            int cnt = (1 << (n2 - prefix.length() - 1));
            if (cnt >= k)
                return dfs(prefix + c, n - 1, k);
            else
                k -= cnt;
        }
        return "";
    }
public:
    string getHappyString(int n, int k) {
        n2 = n;
        return dfs("", n, k);
    }
};