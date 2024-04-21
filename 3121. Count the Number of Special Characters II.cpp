
// Code
// Testcase
// Test Result
// Test Result
// 3121. Count the Number of Special Characters II
// Solved
// Medium
// Companies
// Hint
// You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

// Return the number of special letters in word.

 

// Example 1:

// Input: word = "aaAbcBC"

// Output: 3

// Explanation:

// The special characters are 'a', 'b', and 'c'.

// Example 2:

// Input: word = "abc"

// Output: 0

// Explanation:

// There are no special characters in word.

// Example 3:

// Input: word = "AbBCab"

// Output: 0

// Explanation:

// There are no special characters in word.

 

// Constraints:

// 1 <= word.length <= 2 * 105
// word consists of only lowercase and uppercase English letters.


class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.length();
        int count = 0;
        vector<int>a(150,-1);
        vector<int>b(150,-1);
        for(int i=0;i<n;i++){
            if(s[i]>=65 && s[i]<=90){  
                if(a[s[i]]==-1) a[s[i]]=i; 
            }
            else{  
                b[s[i]]=i;
            }
        } 
        for(int i=0;i<a.size();i++){
            if(a[i]==-1 || b[i+32]==-1) continue;
            if(b[i+32]<a[i]) count++;
        }
        return count;
    }
};