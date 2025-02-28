// 1092. Shortest Common Supersequence 
// Hard
// Topics
// Companies
// Hint
// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.
// Example 2:

// Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
// Output: "aaaaaaaa"
 

// Constraints:

// 1 <= str1.length, str2.length <= 1000
// str1 and str2 consist of lowercase English letters.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 198.9K
// Submissions
// 327.3K
// Acceptance Rate
// 60.8%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (102)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int m=str1.size();
            int n=str2.size();
            vector<vector<int>>dp(m+1,vector<int>(n+1,0));
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    dp[i][j]=(str1[i-1]==str2[j-1])?dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1]);
                }
            }
            string res;
            int i=m;
            int j=n;
            while(i>0 || j>0){
                if(i>0 && dp[i][j]==dp[i-1][j])res+=str1[--i];
                else if(j>0 && dp[i][j]==dp[i][j-1])res+=str2[--j];
                else res+=str1[--i],--j;
            }
            reverse(res.begin(),res.end());
            return res;
        }
    };