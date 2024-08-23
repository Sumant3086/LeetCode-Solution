// 592. Fraction Addition and Subtraction
// Solved
// Medium
// Topics
// Companies

// Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

// The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

//  

// Example 1:

// Input: expression = "-1/2+1/2"
// Output: "0/1"


// Example 2:

// Input: expression = "-1/2+1/2+1/3"
// Output: "1/3"


// Example 3:

// Input: expression = "1/3-1/2"
// Output: "-1/6"


//  

// Constraints:

// The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
// Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
// The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
// The number of given fractions will be in the range [1, 10].
// The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 82.7K
// Submissions
// 132.4K
// Acceptance Rate
// 62.5%
// Topics
// Math
// String
// Simulation
// Companies
// Similar Questions
// Solve the Equation
// Medium
// Discussion (104)
// Choose a type
// Preview
// Comment
// 💡 Discussion Rules

// 1. Please don't post any solutions in this discussion.

// 2. The problem discussion is for asking questions about the problem or for sharing tips - anything except for solutions.

// 3. If you'd like to share your solution for feedback and ideas, please head to the solutions tab and post it there.

// Sort by:Best
// No comments yet.
// 1
// 2
// 3
// 4
// 5
// 6
// 11
// Copyright ©️ 2024 LeetCode All rights reserved

class Solution {
public:
    string fractionAddition(string expression) {
        stringstream ss(expression);
        char op;
        int a,b,c,d;
        int num,den;
        ss>>a;ss>>op;ss>>b; //extracting the 1st 2 numbers
        while(ss>>c) //til we have the number
        {
            ss>>op; // op is the operator. which is '/' in our case
            ss>>d;
            num= a*d + b*c;
            den= b*d;
            a= num/__gcd(abs(num),abs(den));
            b= den/__gcd(abs(num),abs(den));
        }
        c=__gcd(abs(a),abs(b));
        a=a/c;
        b=b/c;
        return to_string(a)+'/'+to_string(b);
    }
};