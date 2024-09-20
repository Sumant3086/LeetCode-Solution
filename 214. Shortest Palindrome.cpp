// 214. Shortest Palindrome
// Solved
// Hard
// Topics
// Companies
// You are given a string s. You can convert s to a 
// palindrome
//  by adding characters in front of it.

// Return the shortest palindrome you can find by performing this transformation.

 

// Example 1:

// Input: s = "aacecaaa"
// Output: "aaacecaaa"
// Example 2:

// Input: s = "abcd"
// Output: "dcbabcd"
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of lowercase English letters only.

class Solution {
public:
    string shortestPalindrome(string s) {
        string revStr=s;
        reverse(revStr.begin(),revStr.end());
        string fullStr=s+"*"+revStr;
        vector<int>lps(fullStr.size(),0);
        for(int i=1;i<fullStr.size();i++){
            int j=lps[i-1];
            while(j>0 && fullStr[i]!=fullStr[j]){
                j=lps[j-1];
            }            
            if(fullStr[i]==fullStr[j]){
                j++;
            }
            lps[i]=j;
        }
        int palind=lps.back();
        string addStr=s.substr(palind);
        reverse(addStr.begin(),addStr.end());
        return addStr+s;
    }
};