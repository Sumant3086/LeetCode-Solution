// 2116. Check if a Parentheses String Can Be Valid
// Medium
// Topics
// Companies
// Hint
// A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

// It is ().
// It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
// It can be written as (A), where A is a valid parentheses string.
// You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

// If locked[i] is '1', you cannot change s[i].
// But if locked[i] is '0', you can change s[i] to either '(' or ')'.
// Return true if you can make s a valid parentheses string. Otherwise, return false.

 

// Example 1:


// Input: s = "))()))", locked = "010100"
// Output: true
// Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
// We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.
// Example 2:

// Input: s = "()()", locked = "0000"
// Output: true
// Explanation: We do not need to make any changes because s is already valid.
// Example 3:

// Input: s = ")", locked = "0"
// Output: false
// Explanation: locked permits us to change s[0]. 
// Changing s[0] to either '(' or ')' will not make s valid.
 

// Constraints:

// n == s.length == locked.length
// 1 <= n <= 105
// s[i] is either '(' or ')'.
// locked[i] is either '0' or '1'.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 70K
// Submissions
// 179.5K
// Acceptance Rate
// 39.0%
// Topics
// String
// Stack
// Greedy
// Companies
// Hint 1
// Hint 2
// Hint 3
// Similar Questions
// Discussion (128)

// Choose a type



// Copyright ©️ 2025 LeetCode All right

class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int>openB;
        stack<int>notL;
        int n=s.size();
        if(n%2!=0){
            return false;
        }
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                notL.push(i);
            }else if(s[i]=='('){
                openB.push(i);
            }else if(s[i]==')'){
                if(!openB.empty()){
                    openB.pop();
                }else if(!notL.empty()){
                    notL.pop();
                }else{
                    return false;
                }
            }
        }
        while(!openB.empty() && !notL.empty() && openB.top()<notL.top()){
            openB.pop();
            notL.pop();
        }
        if(!openB.empty()){
            return false;
        }
        return true;
    }
};