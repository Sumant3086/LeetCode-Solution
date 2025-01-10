// 2185. Counting Words With a Given Prefix
// Solved
// Easy
// Topics
// Companies
// Hint
// You are given an array of strings words and a string pref.

// Return the number of strings in words that contain pref as a prefix.

// A prefix of a string s is any leading contiguous substring of s.

 

// Example 1:

// Input: words = ["pay","attention","practice","attend"], pref = "at"
// Output: 2
// Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
// Example 2:

// Input: words = ["leetcode","win","loops","success"], pref = "code"
// Output: 0
// Explanation: There are no strings that contain "code" as a prefix.
 

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length, pref.length <= 100
// words[i] and pref consist of lowercase English letters.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 257.3K
// Submissions
// 304.5K
// Acceptance Rate
// 84.5%
// Topics
// Companies
// Hint 1
// Similar Questions
// Discussion (280)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

// 1K


// 280





class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(const string& word:words){
            if(word.find(pref)==0){
                count++;
            }
        }
        return count;
    }
};