// 205. Isomorphic Strings
// Solved
// Easy
// Topics
// Companies
// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true
 

// Constraints:

// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map<char,char>mapS,mapT;
        for(int i=0;i<s.size();i++){
            char charS=s[i],charT=t[i];
            if(mapS.count(charS)==0 && mapT.count(charT)==0){
                mapS[charS]=charT;
                mapT[charT]=charS;
            }else{
                if(mapS[charS]!=charT || mapT[charT]!=charS)
                return 0;
            }
        }
        return 1;
    }
};