// 1190. Reverse Substrings Between Each Pair of Parentheses
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a string s that consists of lower case English letters and brackets.

// Reverse the strings in each pair of matching parentheses, starting from the innermost one.

// Your result should not contain any brackets.

 

// Example 1:

// Input: s = "(abcd)"
// Output: "dcba"
// Example 2:

// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole string is reversed.
// Example 3:

// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 

// Constraints:

// 1 <= s.length <= 2000
// s only contains lower case English characters and parentheses.
// It is guaranteed that all parentheses are balanced.


// class Solution {
// public:
//     string reverseParentheses(string s) {
//         stack<int>len;
//         string res;
//         for(char &ch:s){
//             if(ch=='('){
//                 len.push(res.length());
//             }else if(ch==')'){
//                 int temp=len.top();
//                 len.pop();
//                 reverse(begin(res)+temp,end(res));
//             }else{
//                 res.push_back(ch);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
               queue<char>qu;
               while(st.top()!='('){
                qu.push(st.top());
                st.pop();
               }
               st.pop();
               while(qu.size()>0){
                st.push(qu.front());
                qu.pop();
               }
            }
            else{
                st.push(s[i]);
            }
        }
        vector<char>arr(st.size());
        int i=st.size()-1;
        while(i>=0){
            arr[i]=st.top();
            st.pop();
            i--;
        }
        string sta="";
        for(int i=0;i<arr.size();i++){
            sta+=arr[i];
        }
        return sta;
    }
};