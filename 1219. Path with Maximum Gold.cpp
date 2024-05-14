// 1219. Path with Maximum Gold
// Solved
// Medium
// Topics
// Companies
// Hint
// In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

// Return the maximum amount of gold you can collect under the conditions:

// Every time you are located in a cell you will collect all the gold in that cell.
// From your position, you can walk one step to the left, right, up, or down.
// You can't visit the same cell more than once.
// Never visit a cell with 0 gold.
// You can start and stop collecting gold from any position in the grid that has some gold.
 

// Example 1:

// Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
// Output: 24
// Explanation:
// [[0,6,0],
//  [5,8,7],
//  [0,9,0]]
// Path to get the maximum gold, 9 -> 8 -> 7.
// Example 2:

// Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
// Output: 28
// Explanation:
// [[1,0,7],
//  [2,0,6],
//  [3,4,5],
//  [0,3,0],
//  [9,0,20]]
// Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 15
// 0 <= grid[i][j] <= 100
// There are at most 25 cells containing gold.

// class Solution {
// public:
//     int getMaximumGold(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int maxGold=0;
    
//          function<void(int,int,int)>DFS=[&](int i,int j,int currentGold){
//             if (i<0 || i >= m || j < 0 || j >=n || grid[i][j]==0){
//                 return;
//             }
//             int goldInCurrentCell=grid[i][j];
//             currentGold+=goldInCurrentCell;
//             maxGold=max(maxGold,currentGold);
//             int temp=grid[i][j];
//             grid[i][j]=0;

//             DFS(i+1,j,currentGold);
//             DFS(i-1,j,currentGold);
//             DFS(i,j+1,currentGold);
//             DFS(i,j-1,currentGold);
            
//             grid[i][j]=temp;
//         };
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]!=0){
//                     DFS(i,j,0);
//                 }
//             }
//         }
//         return maxGold;
//     }
// };

class Solution {
public:
    int maxi=0;
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    cout<<grid[i][j]<<endl;
                    helper(grid,i,j,0);
                }
            }
        }
        return maxi;
    }
    void helper(vector<vector<int>>&grid,int row,int col,int sum){
        if(row>=grid.size()||row<0 || col>=grid[0].size()|| col<0){
            maxi=max(sum,maxi);
            return ;
        }
        if(grid[row][col]<=0){
            maxi=max(sum,maxi);
            return;
        }
        int val=grid[row][col];
        sum+=grid[row][col];
        grid[row][col]=-1;
        helper(grid,row+1,col,sum);
        helper(grid,row-1,col,sum);
        helper(grid,row,col+1,sum);
        helper(grid,row,col-1,sum);
        grid[row][col]=val;
    }
};