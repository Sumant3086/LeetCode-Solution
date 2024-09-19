// 241. Different Ways to Add Parentheses
// Solved
// Medium
// Topics
// Companies
// Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

// The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

// Example 1:

// Input: expression = "2-1-1"
// Output: [0,2]
// Explanation:
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// Example 2:

// Input: expression = "2*3-4*5"
// Output: [-34,-14,-10,-10,10]
// Explanation:
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10
 

// Constraints:

// 1 <= expression.length <= 20
// expression consists of digits and the operator '+', '-', and '*'.
// All the integer values in the input expression are in the range [0, 99].
// The integer values in the input expression do not have a leading '-' or '+' denoting the sign.

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>results;
        if(expression.length()==0)return results;
        if(expression.length()==1){
            results.push_back(stoi(expression));
            return results;
        }
        if(expression.length()==2 && isdigit(expression[0])){
            results.push_back(stoi(expression));
            return results;
        }
        for(int i=0;i<expression.length();i++){
            char currentChar=expression[i];
            if(isdigit(currentChar))continue;
            vector<int>leftResults=diffWaysToCompute(expression.substr(0,i));
            vector<int>rightResults=diffWaysToCompute(expression.substr(i+1));
            for(int leftValue:leftResults){
                for(int rightValue:rightResults){
                    int computedResult=0;
                    switch(currentChar){
                        case '+':
                            computedResult=leftValue+rightValue;
                            break;
                        case '-':
                            computedResult=leftValue-rightValue;
                            break;
                        case '*':
                            computedResult=leftValue*rightValue;
                            break;
                    }
                    results.push_back(computedResult);
                }
            }
        }
        return results;
    }
};