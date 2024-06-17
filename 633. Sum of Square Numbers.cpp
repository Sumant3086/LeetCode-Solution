// 633. Sum of Square Numbers
// Solved
// Medium
// Topics
// Companies
// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

// Example 1:

// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5
// Example 2:

// Input: c = 3
// Output: false
 

// Constraints:

// 0 <= c <= 231 - 1


class Solution {
public:
    bool judgeSquareSum(int c) {
        long l=0;
        long r=(int)sqrt(c);
        while(l<=r){
            long sum=l*l + r*r;
            if(sum==c){
                return true;
            }else if(sum<c){
                l++;
            }else{
                r--;
            }
        }
        return false;
    }
};