// 3. Longest Substring Without Repeating Characters
// Solved
// Medium
// Topics
// Companies
// Hint
// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 6.8M
// Submissions
// 18.9M
// Acceptance Rate
// 36.0%
// Topics
// Companies
// Hint 1
// Similar Questions
// Discussion (482)

// Choose a type



// Copyright ©️ 2025 LeetCode All ri

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int maxL=0;
        set<char>st;
        for(int r=0;r<s.length();r++){
            while(st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxL=max(maxL,r-l+1);
        }
        return maxL;        
    }
};

// can't use set it gives output 4 in test case 3