// 3403. Find the Lexicographically Largest String From the Box I
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string word, and an integer numFriends.

// Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:

// word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
// All the split words are put into a box.
// Find the lexicographically largest string from the box after all the rounds are finished.

 

// Example 1:

// Input: word = "dbca", numFriends = 2

// Output: "dbc"

// Explanation: 

// All possible splits are:

// "d" and "bca".
// "db" and "ca".
// "dbc" and "a".
// Example 2:

// Input: word = "gggg", numFriends = 4

// Output: "g"

// Explanation: 

// The only possible split is: "g", "g", "g", and "g".

 

// Constraints:

// 1 <= word.length <= 5 * 103
// word consists only of lowercase English letters.
// 1 <= numFriends <= word.length

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 79,274/202.3K
// Acceptance Rate
// 39.2%
// Topics
// icon
// Companies
// Hint 1
// Similar Questions
// Discussion (191)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        string res = "";
        for (int i = 0 ; i < word.size() ; i++) 
            res = max(res, word.substr(i, word.length() - numFriends + 1));
        return res;
    }
};