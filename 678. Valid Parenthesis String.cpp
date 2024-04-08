// 678. Valid Parenthesis String
// Solved
// Medium
// Topics
// Companies
// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "(*)"
// Output: true
// Example 3:

// Input: s = "(*))"
// Output: true
 

// Constraints:

// 1 <= s.length <= 100
// s[i] is '(', ')' or '*'.

class Solution {
public:
    bool checkValidString(string s) {
        int OB=0,CB=0;
        for(char c:s){
            if(c=='('){
                OB++;
                CB++;
            }else if(c==')'){
                OB--;
                CB--;
            }else{
                OB--;
                CB++;
            }
            if(CB<0)return false;
            if(OB<0)OB=0;
        }
        return OB==0;
    }
};