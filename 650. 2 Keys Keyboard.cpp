// 650. 2 Keys Keyboard
// Solved
// Medium
// Topics
// Companies
// Hint
// There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

// Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
// Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

 

// Example 1:

// Input: n = 3
// Output: 3
// Explanation: Initially, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.
// Example 2:

// Input: n = 1
// Output: 0
 

// Constraints:

// 1 <= n <= 1000

// class Solution {
// public:
// int solve(int currA,int clipA,int n){
//     if(currA==n){
//         return 0;
//     }
//     if(currA>n){
//         return 100000;
//     }
//     int copyAllPaste=1+1+solve(currA+currA,currA,n);
//     int paste=1+solve(currA+clipA,clipA,n);
//     return min(copyAllPaste,paste);
// }
//     int minSteps(int n) {
//         if(n==1){
//             return 0;
//         }
//         return 1+solve(1,1,n);
//     }
// };

class Solution {
private:
public:
    int minSteps(int n) {
        vector<int> primeFactors;
        int cnt=0;
        int d = 2;
        while (n>1){
            while (n%d==0) {
                cnt+=d;
                n/=d;
            }
            d++;
            if (d*d>n) break;
        }
        if (n!=1) cnt+=n;
        return cnt;
    }
};
