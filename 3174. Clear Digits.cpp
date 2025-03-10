// 3174. Clear Digits
// Solved
// Easy
// Topics
// Companies
// Hint
// You are given a string s.

// Your task is to remove all digits by doing this operation repeatedly:

// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.

 

// Example 1:

// Input: s = "abc"

// Output: "abc"

// Explanation:

// There is no digit in the string.

// Example 2:

// Input: s = "cb34"

// Output: ""

// Explanation:

// First, we apply the operation on s[2], and s becomes "c4".

// Then we apply the operation on s[1], and s becomes "".

 

// Constraints:

// 1 <= s.length <= 100
// s consists only of lowercase English letters and digits.
// The input is generated such that it is possible to delete all digits.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 173.6K
// Submissions
// 212.7K
// Acceptance Rate
// 81.6%
// Topics
// Companies
// Hint 1
// Hint 2
// Discussion (143)

// Choose a type



// Copyright ©️ 2025 

class Solution {
    public:
        string clearDigits(string s) {
            int n=s.size();
            string res="";
            vector<int>stack;
            for(int i=0;i<n;i++){
                if(isdigit(s[i]) && !res.empty()){
                res.pop_back();
                }else{
                    res+=s[i];
                }
            }
            return res;
        }
    };