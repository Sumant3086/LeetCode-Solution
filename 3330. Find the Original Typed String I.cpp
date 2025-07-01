// 3330. Find the Original Typed String I
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

// Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.

// You are given a string word, which represents the final output displayed on Alice's screen.

// Return the total number of possible original strings that Alice might have intended to type.

 

// Example 1:

// Input: word = "abbcccc"

// Output: 5

// Explanation:

// The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".

// Example 2:

// Input: word = "abcd"

// Output: 1

// Explanation:

// The only possible string is "abcd".

// Example 3:

// Input: word = "aaaa"

// Output: 4

 

// Constraints:

// 1 <= word.length <= 100
// word consists only of lowercase English letters.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 53,437/84.7K
// Acceptance Rate
// 63.1%
// Topics
// String
// icon
// Companies
// Hint 1
// Any group of consecutive characters might have been the mistake.
// Similar Questions
// Discussion (95)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.

// 139


// 95




class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        int tot=1;
        int i=0;
        while(i<n){
            int j=i;
            while(j<n && word[j]==word[i]){
                j++;
            }
            int len=j-i;
            if(len>=2){
                tot+=(len-1);
            }
            i=j;
        }
        return tot;
    }
};
// class Solution {
// public:
//     int possibleStringCount(string word) {
//         int n=word.size();
//         int ans=n;
//         for(int i=1;i<n;i++){
//             if(word[i]!=word[i-1]){
//                 ans--;
//             }
//         }
//         return ans;
//     }
// };
