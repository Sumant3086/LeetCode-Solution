// 1957. Delete Characters to Make Fancy String
// Solved
// Easy
// Topics
// Companies
// Hint
// A fancy string is a string where no three consecutive characters are equal.

// Given a string s, delete the minimum possible number of characters from s to make it fancy.

// Return the final string after the deletion. It can be shown that the answer will always be unique.

 

// Example 1:

// Input: s = "leeetcode"
// Output: "leetcode"
// Explanation:
// Remove an 'e' from the first group of 'e's to create "leetcode".
// No three consecutive characters are equal, so return "leetcode".
// Example 2:

// Input: s = "aaabaaaa"
// Output: "aabaa"
// Explanation:
// Remove an 'a' from the first group of 'a's to create "aabaaaa".
// Remove two 'a's from the second group of 'a's to create "aabaa".
// No three consecutive characters are equal, so return "aabaa".
// Example 3:

// Input: s = "aab"
// Output: "aab"
// Explanation: No three consecutive characters are equal, so return "aab".
 

// Constraints:

// 1 <= s.length <= 105
// s consists only of lowercase English letters.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 113.6K
// Submissions
// 161.7K
// Acceptance Rate
// 70.3%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (123)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3)return s;
        int r=2;
        for(int l=2;l<s.size();l++){
            if(s[l]!=s[r-1] || s[l]!=s[r-2]){
                s[r++]=s[l];
            }
        }
        s.resize(r);
        return s;
    }
};