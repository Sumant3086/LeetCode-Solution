// 1400. Construct K Palindrome Strings
// Solved
// Medium
// Topics
// Companies
// Hint
// Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

 

// Example 1:

// Input: s = "annabelle", k = 2
// Output: true
// Explanation: You can construct two palindromes using all characters in s.
// Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
// Example 2:

// Input: s = "leetcode", k = 3
// Output: false
// Explanation: It is impossible to construct 3 palindromes using all the characters of s.
// Example 3:

// Input: s = "true", k = 4
// Output: true
// Explanation: The only possible solution is to put each character in a separate string.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.
// 1 <= k <= 105
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 57K
// Submissions
// 91.8K
// Acceptance Rate
// 62.1%
// Topics
// Hash Table
// String
// Greedy
// Counting
// Companies
// Hint 1
// Hint 2
// Hint 3
// Discussion (17)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

// 1.1K


// 17





class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        int sing=0;
        int doub=0;
        for(auto &[ch,freq]:mp){
            doub+=freq/2;
            if(freq%2==1){
                sing++;
            }
        }
        return (sing<=k && k<=s.size());
    }
};