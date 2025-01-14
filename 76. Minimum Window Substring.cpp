// 76. Minimum Window Substring
// Solved
// Hard
// Topics
// Companies
// Hint
// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
 

// Follow up: Could you find an algorithm that runs in O(m + n) time?

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 1.6M
// Submissions
// 3.6M
// Acceptance Rate
// 44.3%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Hint 4
// Similar Questions
// Discussion (225)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

// 18.4K


// 225





class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        vector<int>freq(128,0);
        int n=s.size();
        int count=0,l=0,r=0,minL=INT_MAX,curr=0;
        for(char c:t){
            freq[c]++;
        }
        while(r<n){
            if(freq[s[r]]>0)count++;
            freq[s[r]]--;
            r++;
            while(count==t.size()){
                if(r-l<minL){
                    minL=r-l;
                    curr=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0)count--;
                l++;
            }
        }
        return minL==INT_MAX?"":s.substr(curr,minL);
    }
};