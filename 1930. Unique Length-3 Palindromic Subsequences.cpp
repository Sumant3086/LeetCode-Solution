// 1930. Unique Length-3 Palindromic Subsequences
// Solved
// Medium
// Topics
// Companies
// Hint
// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
 

// Example 1:

// Input: s = "aabca"
// Output: 3
// Explanation: The 3 palindromic subsequences of length 3 are:
// - "aba" (subsequence of "aabca")
// - "aaa" (subsequence of "aabca")
// - "aca" (subsequence of "aabca")
// Example 2:

// Input: s = "adc"
// Output: 0
// Explanation: There are no palindromic subsequences of length 3 in "adc".
// Example 3:

// Input: s = "bbcbaba"
// Output: 4
// Explanation: The 4 palindromic subsequences of length 3 are:
// - "bbb" (subsequence of "bbcbaba")
// - "bcb" (subsequence of "bbcbaba")
// - "bab" (subsequence of "bbcbaba")
// - "aba" (subsequence of "bbcbaba")
 

// Constraints:

// 3 <= s.length <= 105
// s consists of only lowercase English letters.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 129.9K
// Submissions
// 193.1K
// Acceptance Rate
// 67.3%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (99)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

// 1.9K


// 99




class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res=0;
        int n=s.length();
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]].first=i;
            }
            mp[s[i]].second=i;
        }
        for(auto& [ch,pos]:mp){
            int left=pos.first;
            int right=pos.second;
            if(right-left<=1)continue;
            unordered_set<char>uniq;
            for(int i=left+1;i<right;i++){
                uniq.insert(s[i]);
            }
            res+=uniq.size();
        }
        return res;
    }
};