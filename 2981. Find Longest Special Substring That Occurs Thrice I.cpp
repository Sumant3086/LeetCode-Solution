// 2981. Find Longest Special Substring That Occurs Thrice I
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a string s that consists of lowercase English letters.

// A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.

// Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.

// A substring is a contiguous non-empty sequence of characters within a string.

 

// Example 1:

// Input: s = "aaaa"
// Output: 2
// Explanation: The longest special substring which occurs thrice is "aa": substrings "aaaa", "aaaa", and "aaaa".
// It can be shown that the maximum length achievable is 2.
// Example 2:

// Input: s = "abcdef"
// Output: -1
// Explanation: There exists no special substring which occurs at least thrice. Hence return -1.
// Example 3:

// Input: s = "abcaba"
// Output: 1
// Explanation: The longest special substring which occurs thrice is "a": substrings "abcaba", "abcaba", and "abcaba".
// It can be shown that the maximum length achievable is 1.
 

// Constraints:

// 3 <= s.length <= 50
// s consists of only lowercase English letters.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 37.7K
// Submissions
// 75.8K
// Acceptance Rate
// 49.7%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (47)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        int left=1;
        int right=n;
        if(!helper(s,n,left))return -1;
        while(left+1<right){
            int mid=(left+right)/2;
            if(helper(s,n,mid))left=mid;
            else right=mid;
        }
        return left;
    }
    private:
    bool helper(const string& s,int n,int x){
        vector<int>count(26,0);
        int idx=0;
        for(int i=0;i<n;i++){
            while(s[idx]!=s[i]) idx++;
            if(i-idx+1>=x) count[s[i]-'a']++;
            if(count[s[i]-'a']>2)return true;
        }
        return false;
    }
};