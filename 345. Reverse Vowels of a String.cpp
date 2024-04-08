// 345. Reverse Vowels of a String
// Easy
// Topics
// Companies
// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

// Example 1:

// Input: s = "hello"
// Output: "holle"
// Example 2:

// Input: s = "leetcode"
// Output: "leotcede"
 

// Constraints:

// 1 <= s.length <= 3 * 105
// s consist of printable ASCII characters.

class Solution {
public:
    string reverseVowels(string s) {
        int start=0;
        int end=s.length()-1;
        string st="aeiouAEIOU";
        while(start<end){
            bool b1=false;
            bool b2=false;

            for(char ch:st){
                if(ch==s.at(start)) 
                b1=true;
            }
            if(!b1){
                start++;
                continue;
            }
            for(char ch:st){
                if(ch==s.at(end))
                b2=true;
            }
            if(!b2){
                end--;
                continue;
            }
            char temp=s.at(start);
            s.at(start)=s.at(end);
            s.at(end)=temp;
            start++;
            end--;
        }
        return s;
    }
};