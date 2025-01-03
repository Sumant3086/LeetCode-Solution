// 1277. Count Square Submatrices with All Ones
// Solved
// Medium
// Topics
// Companies
// Hint
// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

// Example 1:

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation: 
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.
// Example 2:

// Input: matrix = 
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]
// Output: 7
// Explanation: 
// There are 6 squares of side 1.  
// There is 1 square of side 2. 
// Total number of squares = 6 + 1 = 7.
 

// Constraints:

// 1 <= arr.length <= 300
// 1 <= arr[0].length <= 300
// 0 <= arr[i][j] <= 1

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 244.1K
// Submissions
// 321.6K
// Acceptance Rate
// 75.9%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (24)

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        int res=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==1){
                    dp[i+1][j+1]=min({dp[i][j+1],dp[i+1][j],dp[i][j]})+1;
                    res+=dp[i+1][j+1];
                }
            }
        }
        return res;
    }
};