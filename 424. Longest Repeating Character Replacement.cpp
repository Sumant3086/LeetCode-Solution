// 424. Longest Repeating Character Replacement
// Attempted
// Medium
// Topics
// Companies
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 966.1K
// Submissions
// 1.7M
// Acceptance Rate
// 56.0%
// Topics
// Hash Table
// String
// Sliding Window
// Companies
// Similar Questions
// Discussion (153)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int n=s.size();
        int maxF=0;
        int maxL=0;
        unordered_map<char,int>mp;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            maxF=max(maxF,mp[s[r]]); 
            if(r-l+1-maxF>k){
                mp[s[l]]--;
                l++;
            }
            maxL=max(maxL,r-l+1);
        }
        return maxL;
    }
};
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n=s.size();
//         int maxF=0;
//         int maxL=0;
//         for(int i=0;i<n;i++){
//             map<char,int>mp;
//             for(int j=i;j<n;j++){
//                 mp[s[j]]++;
//                 maxF=max(maxF,mp[s[j]]);
//                 int changes=(j-i+1)-maxF;
//                 if(changes<=k){
//                     maxL=max(maxL,j-i+1);
//                 }else{
//                     break;
//                 }
//             }
//         }
//         return maxL;
//     }
// };