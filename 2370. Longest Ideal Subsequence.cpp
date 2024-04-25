// 2370. Longest Ideal Subsequence
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

// t is a subsequence of the string s.
// The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
// Return the length of the longest ideal string.

// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

// Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.

 

// Example 1:

// Input: s = "acfgbd", k = 2
// Output: 4
// Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
// Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
// Example 2:

// Input: s = "abcd", k = 3
// Output: 4
// Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.
 

// Constraints:

// 1 <= s.length <= 105
// 0 <= k <= 25
// s consists of lowercase English letters.

class Solution {
public:
    int longestIdealString(string s, int k) {
        int total[26]={0};//longest seq ends with i+'a'
        int res=0;
        for(char c:s){
            int i=c-'a';
            int m1=max(0,i-k);
            int m2=min(i+k,25);
            for(int j=m1;j<=m2;j++)
                total[i]=max(total[i],total[j]);//longest seq ends with j+'a'
                total[i]++;
        }
        return *max_element(total,total+26);
    }
};