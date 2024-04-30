// 1915. Number of Wonderful Substrings
// Solved
// Medium
// Topics
// Companies
// Hint
// A wonderful string is a string where at most one letter appears an odd number of times.

// For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
// Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: word = "aba"
// Output: 4
// Explanation: The four wonderful substrings are underlined below:
// - "aba" -> "a"
// - "aba" -> "b"
// - "aba" -> "a"
// - "aba" -> "aba"
// Example 2:

// Input: word = "aabb"
// Output: 9
// Explanation: The nine wonderful substrings are underlined below:
// - "aabb" -> "a"
// - "aabb" -> "aa"
// - "aabb" -> "aab"
// - "aabb" -> "aabb"
// - "aabb" -> "a"
// - "aabb" -> "abb"
// - "aabb" -> "b"
// - "aabb" -> "bb"
// - "aabb" -> "b"
// Example 3:

// Input: word = "he"
// Output: 2
// Explanation: The two wonderful substrings are underlined below:
// - "he" -> "h"
// - "he" -> "e"

// class Solution {
// public:
//     long long wonderfulSubstrings(string word) {
//         unordered_map<int,int>count;
//         int ans=0;
//         count[0]=1;
//         long long res=0;
//         for(char c:word){
//             ans^=1 << (c-'a');
//             res+=count[ans];
//             for(int i=0;i<10;i++){
//                 res+=count[ans^(1<<i)];
//             }
//             count[ans]++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        vector<int>cnt(1024,0);
        cnt[0]=1;
        int mask=0;
        for(auto c: word)
        {
            mask= mask ^ (1<<(c-'a'));
            ans+=cnt[mask];
          
            for(int i=0;i<10;i++)
            {
               int newmask= mask ^ (1<<i);
                ans+=cnt[newmask];
            }
            cnt[mask]++;
        }
        return ans;
    }
};