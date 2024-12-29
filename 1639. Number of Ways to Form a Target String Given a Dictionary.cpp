// 1639. Number of Ways to Form a Target String Given a Dictionary
// Solved
// Hard
// Topics
// Companies
// Hint
// You are given a list of strings of the same length words and a string target.

// Your task is to form target using the given words under the following rules:

// target should be formed from left to right.
// To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
// Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
// Repeat the process until you form the string target.
// Notice that you can use multiple characters from the same string in words provided the conditions above are met.

// Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: words = ["acca","bbbb","caca"], target = "aba"
// Output: 6
// Explanation: There are 6 ways to form target.
// "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
// "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
// "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
// "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
// "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
// "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
// Example 2:

// Input: words = ["abba","baab"], target = "bab"
// Output: 4
// Explanation: There are 4 ways to form target.
// "bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
// "bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
// "bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
// "bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")
 

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 1000
// All strings in words have the same length.
// 1 <= target.length <= 1000
// words[i] and target contain only lowercase English letters.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 82K
// Submissions
// 151.6K
// Acceptance Rate
// 54.1%
// Topics
// Companies
// Hint 1
// Hint 2
// Discussion (114)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

class Solution {
public:
    vector<vector<int>> A; 
    vector<vector<int>> dp; 
    const int mod = 1e9 + 7;
    int F(int i, int j, string &T, vector<string> &W) {
        if (j == T.size()) {
            return 1; 
        }
        if (i == A.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; 
        }
        long long count = F(i + 1, j, T, W);
        count %= mod;
        count += (1LL * A[i][T[j] - 'a'] * F(i + 1, j + 1, T, W)) % mod;
        count %= mod;
        return dp[i][j] = count;
    }

    int numWays(vector<string>& W, string T) {
        int n = W.size();
        int m = W[0].size();
        A = vector<vector<int>>(m, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[j][W[i][j] - 'a']++;
            }
        }
        dp = vector<vector<int>>(m, vector<int>(T.size(), -1));
        return F(0, 0, T, W);
    }
};