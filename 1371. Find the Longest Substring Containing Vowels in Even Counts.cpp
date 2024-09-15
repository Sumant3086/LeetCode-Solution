// 1371. Find the Longest Substring Containing Vowels in Even Counts
// Solved
// Medium
// Topics
// Companies
// Hint
// Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

 

// Example 1:

// Input: s = "eleetminicoworoep"
// Output: 13
// Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
// Example 2:

// Input: s = "leetcodeisgreat"
// Output: 5
// Explanation: The longest substring is "leetc" which contains two e's.
// Example 3:

// Input: s = "bcbcbc"
// Output: 6
// Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 

// Constraints:

// 1 <= s.length <= 5 x 10^5
// s contains only lowercase English letters.


class Solution {
public:
    int findTheLongestSubstring(string s) {
        const string vowels="aeiou";
        int res=0;
        int prefix=0;
        unordered_map<int,int>mp{{0,-1}};
        for(int i=0;i<s.length();i++){
            const int idx=vowels.find(s[i]);
            if(idx!=-1){
                prefix^=1<<idx;
            }
            if(!mp.contains(prefix)){
                mp[prefix]=i;
            }
            res=max(res,i-mp[prefix]);
        }
        return res;
    }
};        


// class Solution {
// public:
//     bool areVowelsEven(vector<int>& vowelCount) {
//         // Check if all vowel counts are even
//         for (int count : vowelCount) {
//             if (count % 2 != 0) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     int findTheLongestSubstring(string s) {
//         int n = s.length();
//         int maxLength = 0;
 
//         for (int start = 0; start < n; ++start) {
//             vector<int> vowelCount(5, 0);   
 
//             for (int end = start; end < n; ++end) { 
//                 if (s[end] == 'a') vowelCount[0]++;
//                 else if (s[end] == 'e') vowelCount[1]++;
//                 else if (s[end] == 'i') vowelCount[2]++;
//                 else if (s[end] == 'o') vowelCount[3]++;
//                 else if (s[end] == 'u') vowelCount[4]++;
 
//                 if (areVowelsEven(vowelCount)) {
//                     maxLength = max(maxLength, end - start + 1);
//                 }
//             }
//         }

//         return maxLength;
//     }
// };
