// 796. Rotate String
// Solved
// Easy
// Topics
// Companies
// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.
 

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false
 

// Constraints:

// 1 <= s.length, goal.length <= 100
// s and goal consist of lowercase English letters.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 401.3K
// Submissions
// 667.4K
// Acceptance Rate
// 60.1%
// Topics
// Companies
// Discussion (75)

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        int m=goal.length();
        if(n!=m)return false;
        string full=s+s;
        return full.find(goal)<full.length();
    }
};