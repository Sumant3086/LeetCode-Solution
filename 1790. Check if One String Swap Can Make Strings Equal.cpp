// 1790. Check if One String Swap Can Make Strings Equal
// Easy
// Topics
// Companies
// Hint
// You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

// Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 

// Example 1:

// Input: s1 = "bank", s2 = "kanb"
// Output: true
// Explanation: For example, swap the first character with the last character of s2 to make "bank".
// Example 2:

// Input: s1 = "attack", s2 = "defend"
// Output: false
// Explanation: It is impossible to make them equal with one string swap.
// Example 3:

// Input: s1 = "kelb", s2 = "kelb"
// Output: true
// Explanation: The two strings are already equal, so no string swap operation is required.
 

// Constraints:

// 1 <= s1.length, s2.length <= 100
// s1.length == s2.length
// s1 and s2 consist of only lowercase English letters.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 238.5K
// Submissions
// 490.8K
// Acceptance Rate
// 48.6%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (180)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

// 1.5K


// 180






class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        vector<int>diff;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
            diff.push_back(i);
            }
        }
        if(diff.size()==2){
            return s1[diff[0]]==s2[diff[1]] && s1[diff[1]]==s2[diff[0]];
        }
        return false;
    }
};