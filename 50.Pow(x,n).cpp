// 50. Pow(x, n)
// Solved
// Medium
// Topics
// Companies
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n is an integer.
// Either x is not zero or n > 0.
// -104 <= xn <= 104


// class Solution {
// public:
//     double myPow(double x, int n) {
//         double result =pow(x,n);
//     return result;
//     }
// };


class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) {
            return 1.0;
        }
        double result=1.0;
        long long pow=n;
        if(n<0){
            x=1/x;
            pow=-pow; 
        }
        while(pow>0){
            if (pow%2==1){
                result*=x;
            }
            x*=x;
            pow/=2;
        }
        return result;
    }
};