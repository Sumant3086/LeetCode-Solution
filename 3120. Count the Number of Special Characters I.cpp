// 3120. Count the Number of Special Characters I
// Solved
// Easy
// Companies
// Hint
// You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

// Return the number of special letters in word.

 

// Example 1:

// Input: word = "aaAbcBC"

// Output: 3

// Explanation:

// The special characters in word are 'a', 'b', and 'c'.

// Example 2:

// Input: word = "abc"

// Output: 0

// Explanation:

// No character in word appears in uppercase.

// Example 3:

// Input: word = "abBCab"

// Output: 1

// Explanation:

// The only special character in word is 'b'.

 

// Constraints:

// 1 <= word.length <= 50
// word consists of only lowercase and uppercase English letters.

// class Solution {
// public:
//     int numberOfSpecialChars(string word) {
//         unordered_set<int> s;
//         for(char c:word) {
//             if(islower(c) && !s.count(c)) {
//                 for(char p:word) {
//                     if(toupper(c)==p){
//                         s.insert(c);
//                         break;
//                     }
//                 }
//             }
//         }
//         return s.size();
//     }
// };


class Solution {
public:
    int numberOfSpecialChars(string s) {
        set<int>string1;
        set<int>string2;
        for(auto i:s) {
            if(i>='a' && i<='z')
                string1.insert(i-'a');
            else
                string2.insert(i-'A');
        }
        int c=0;
        for(auto i:string1) {
            if(string2.find(i)!=string2.end())
                c++;
        }
        return c;
    }
};