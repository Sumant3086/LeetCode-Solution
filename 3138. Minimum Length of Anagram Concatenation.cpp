// 3138. Minimum Length of Anagram Concatenation
// Solved
// Medium
// Companies
// Hint
// You are given a string s, which is known to be a concatenation of anagrams of some string t.

// Return the minimum possible length of the string t.

// An anagram is formed by rearranging the letters of a string. For example, "aab", "aba", and, "baa" are anagrams of "aab".

 

// Example 1:

// Input: s = "abba"

// Output: 2

// Explanation:

// One possible string t could be "ba".

// Example 2:

// Input: s = "cdef"

// Output: 4

// Explanation:

// One possible string t could be "cdef", notice that t can be equal to s.

 

// Constraints:

// 1 <= s.length <= 105
// s consist only of lowercase English letters.

class Solution {
public:
    int minAnagramLength(string s) {
        unordered_map<char, int> map;
        for(char c:s){
            map[c]++;   
        }
        int minFreq=map[s[0]];
        for(auto pair:map){
            minFreq=gcd(minFreq,pair.second);
        }
        return (s.length()/minFreq); 
    }
};