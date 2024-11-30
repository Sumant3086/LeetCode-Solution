// 1392. Longest Happy Prefix
// Solved
// Hard
// Topics
// Companies
// Hint
// A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

// Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

 

// Example 1:

// Input: s = "level"
// Output: "l"
// Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
// Example 2:

// Input: s = "ababab"
// Output: "abab"
// Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.
 

// Constraints:

// 1 <= s.length <= 105
// s contains only lowercase English letters.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 54.2K
// Submissions
// 114.5K
// Acceptance Rate
// 47.3%
// Topics
// Companies
// Hint 1
// Similar Questions
// Discussion (26)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved


class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        if(n==0) return "";
        vector<int> ans(n,0);
        int pre=0;
        int suf=1;
        while(suf<n)
        {
            if(s[pre]==s[suf]){
                ans[suf]=pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre==0){
                    ans[suf]=0;
                    suf++;
                }
                else{
                    pre=ans[pre-1];
                }
            }
            
        }
        return s.substr(0,pre);
    }
};