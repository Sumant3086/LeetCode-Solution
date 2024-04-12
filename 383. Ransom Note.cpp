// 383. Ransom Note
// Solved
// Easy
// Topics
// Companies
// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true
 

// Constraints:

// 1 <= ransomNote.length, magazine.length <= 105
// ransomNote and magazine consist of lowercase English letters.


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto __untie_cin = cin.tie(nullptr);
auto __unsync_ios_stdio = ios_base::sync_with_stdio(false);          

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::vector<int> freq(26, 0);
        for (char& c : magazine)
            freq[c - 'a']++;
        for (char& c : ransomNote) {
            if (freq[c - 'a'] <= 0)
                return false;
            freq[c - 'a']--;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         unordered_map<char,int>words;
//         for(char c:magazine){
//             if(words.find(c)==words.end()){
//                 words[c]=1;
//             }else{
//                 words[c]++;
//             }
//         }
//         for(char c:ransomNote){
//             if(words.find(c)!=words.end() && words[c]>0){
//                 words[c]--;
//             }else{
//                 return false;
//             }
//         }
//         return true;
//     }
// };