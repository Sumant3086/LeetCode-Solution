// 1408. String Matching in an Array
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

// A substring is a contiguous sequence of characters within a string

 

// Example 1:

// Input: words = ["mass","as","hero","superhero"]
// Output: ["as","hero"]
// Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
// ["hero","as"] is also a valid answer.
// Example 2:

// Input: words = ["leetcode","et","code"]
// Output: ["et","code"]
// Explanation: "et", "code" are substring of "leetcode".
// Example 3:

// Input: words = ["blue","green","bu"]
// Output: []
// Explanation: No string of words is substring of another string.
 

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 30
// words[i] contains only lowercase English letters.
// All the strings of words are unique.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 134K
// Submissions
// 201.9K
// Acceptance Rate
// 66.3%
// Topics
// Companies
// Hint 1
// Similar Questions
// Discussion (85)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

// 1.1K


// 85





class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(words[j]==words[i]){
                    continue;
                }
                if(words[j].find(words[i])!=string::npos){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};