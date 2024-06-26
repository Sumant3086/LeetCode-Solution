// 1456. Maximum Number of Vowels in a Substring of Given Length
// Solved
// Medium
// Topics
// Companies
// Hint
// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
// Example 2:

// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.
// Example 3:

// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.
// 1 <= k <= s.length

// class Solution {
// public:
//     int maxVowels(string s, int k) {
//         int  maxV=0;
//         int windowV=0;
//         unordered_set<char>v;
//         v.insert('a');
//         v.insert('e');
//         v.insert('i');
//         v.insert('o');
//         v.insert('u');
//         for(int i=0;i<k;i++)
//         if(v.count(s[i]))
//         windowV++;
//         maxV=windowV;
//         for(int i=k;i<s.size();i++){
//             if(v.count(s[i-k]))
//             windowV--;
//             if(v.count(s[i]))
//             windowV++;
//             maxV=max(maxV,windowV);
//         }
//         return maxV;
//     }
// }; 

 
class Solution {
public:
    int maxVowels(string_view s, int k) {
        vector<bool> vow(256, false);
        vow['a']=true;
        vow['e']=true;
        vow['i']=true;
        vow['o']=true;
        vow['u']=true;
        int window=0,cnt=0;
        for(int i=0;i<s.size();++i) {
            if(vow[s[i]])
                ++cnt;
            if(i>=k-1){
                window=max(window,cnt);
                if(vow[s[i-k+1]])
                    --cnt;
            }
        }
        return window;
    }
};
