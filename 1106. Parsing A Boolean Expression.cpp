// 1106. Parsing A Boolean Expression
// Solved
// Hard
// Topics
// Companies
// Hint
// A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

// 't' that evaluates to true.
// 'f' that evaluates to false.
// '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
// '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
// '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
// Given a string expression that represents a boolean expression, return the evaluation of that expression.

// It is guaranteed that the given expression is valid and follows the given rules.

 

// Example 1:

// Input: expression = "&(|(f))"
// Output: false
// Explanation: 
// First, evaluate |(f) --> f. The expression is now "&(f)".
// Then, evaluate &(f) --> f. The expression is now "f".
// Finally, return false.
// Example 2:

// Input: expression = "|(f,f,f,t)"
// Output: true
// Explanation: The evaluation of (false OR false OR false OR true) is true.
// Example 3:

// Input: expression = "!(&(f,t))"
// Output: true
// Explanation: 
// First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
// Then, evaluate !(f) --> NOT false --> true. We return true.
 

// Constraints:

// 1 <= expression.length <= 2 * 104
// expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 44.4K
// Submissions
// 70.7K
// Acceptance Rate
// 62.8%
// Topics
// Companies
// Hint 1
// Discussion (41)

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(auto ch : expression) {
            if(ch == ',' || ch == '(') continue;

            if(ch == '|' || ch == '!' || ch == '&' || ch == 'f' || ch == 't'){
                st.push(ch);
            }
            else if(ch == ')') {
                bool hasTrue = false, hasFalse = false;
                while(st.top() != '!' && st.top() != '|' && st.top() != '&')  {
                    char curTop = st.top();
                    st.pop();
                    if(curTop == 'f') hasFalse = true;
                    if(curTop == 't') hasTrue = true;
                }

                char op = st.top();
                st.pop();
                if(op == '!') {
                    st.push(hasTrue ? 'f' : 't');
                } else if(op == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } else {
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};