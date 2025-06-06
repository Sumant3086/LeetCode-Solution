// 2434. Using a Robot to Print the Lexicographically Smallest String
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

// Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
// Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
// Return the lexicographically smallest string that can be written on the paper.

 

// Example 1:

// Input: s = "zza"
// Output: "azz"
// Explanation: Let p denote the written string.
// Initially p="", s="zza", t="".
// Perform first operation three times p="", s="", t="zza".
// Perform second operation three times p="azz", s="", t="".
// Example 2:

// Input: s = "bac"
// Output: "abc"
// Explanation: Let p denote the written string.
// Perform first operation twice p="", s="c", t="ba". 
// Perform second operation twice p="ab", s="c", t="". 
// Perform first operation p="ab", s="", t="c". 
// Perform second operation p="abc", s="", t="".
// Example 3:

// Input: s = "bdda"
// Output: "addb"
// Explanation: Let p denote the written string.
// Initially p="", s="bdda", t="".
// Perform first operation four times p="", s="", t="bdda".
// Perform second operation four times p="addb", s="", t="".
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only English lowercase letters.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 41,210/80.2K
// Acceptance Rate
// 51.4%
// Topics
// icon
// Companies
// Hint 1
// Hint 2
// Hint 3
// Similar Questions
// Discussion (99)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.

class Solution {
public:
    string robotWithString(string s) {
        string ans = "";
        string t = "";
        
        unordered_map<char, int> frq;
        for (char c : s) {
            frq[c]++;
        }

        char sml = 'a';

        for (char c : s) {
            // if current char is smallest, push to ans directly
            if (c == sml) {
                ans += c;
            } 
            else {
                t.push_back(c);
            }

            // decrease used frequency
            frq[c]--;
            if (frq[c] == 0) {
                frq.erase(c);
            }

            // update sml to next smallest available char
            while (sml <= 'z' && frq.count(sml) == 0) {
                sml++;
            }

            // pop from t if top <= sml
            while (!t.empty() && t.back() <= sml) {
                ans += t.back();
                t.pop_back();
            }
        }

        // empty the remaining stack
        while (!t.empty()) {
            ans += t.back();
            t.pop_back();
        }

        return ans;
    }
};