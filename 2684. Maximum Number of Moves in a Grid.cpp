// 2684. Maximum Number of Moves in a Grid
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed m x n matrix grid consisting of positive integers.

// You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

// From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
// Return the maximum number of moves that you can perform.

 

// Example 1:


// Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
// Output: 3
// Explanation: We can start at the cell (0, 0) and make the following moves:
// - (0, 0) -> (0, 1).
// - (0, 1) -> (1, 2).
// - (1, 2) -> (2, 3).
// It can be shown that it is the maximum number of moves that can be made.
// Example 2:


// Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
// Output: 0
// Explanation: Starting from any cell in the first column we cannot perform any moves.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 2 <= m, n <= 1000
// 4 <= m * n <= 105
// 1 <= grid[i][j] <= 106
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 91.4K
// Submissions
// 157.9K
// Acceptance Rate
// 57.9%
// Topics
// Companies
// Hint 1
// Hint 2
// Discussion (108)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

// 778


// 108




class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        int move=0;
        for(int j=1;j<n;j++){
            for(int i=0;i<m;i++){
                if(grid[i][j]>grid[i][j-1] && dp[i][j-1]>0){
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
                }
                if(i-1>=0 && grid[i][j]>grid[i-1][j-1] && dp[i-1][j-1]>0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
                if(i+1<m && grid[i][j]>grid[i+1][j-1] && dp[i+1][j-1]>0){
                    dp[i][j]=max(dp[i][j],dp[i+1][j-1]+1);
                }
                move=max(move,dp[i][j]-1);
            }
        }
        return move;
    }
};