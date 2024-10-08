// 1568. Minimum Number of Days to Disconnect Island
// Solved
// Hard
// Topics
// Companies
// Hint
// You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

// The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

// In one day, we are allowed to change any single land cell (1) into a water cell (0).

// Return the minimum number of days to disconnect the grid.

 

// Example 1:


// Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

// Output: 2
// Explanation: We need at least 2 days to get a disconnected grid.
// Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
// Example 2:


// Input: grid = [[1,1]]
// Output: 2
// Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 30
// grid[i][j] is either 0 or 1.

class Solution {
public:
int n,m;
void DFS(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis){
    if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || grid[i][j]==0){
        return ;
    }
    vis[i][j]=true;
    DFS(grid,i+1,j,vis);
    DFS(grid,i-1,j,vis);
    DFS(grid,i,j+1,vis);
    DFS(grid,i,j-1,vis);
}
int numOfIsLandsUtil(vector<vector<int>>& grid){
    vector<vector<bool>>vis(m,vector<bool>(n,false));
    int isLands=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !vis[i][j]){
                isLands++;
                DFS(grid,i,j,vis);
            }
        }
    }
    return isLands;
}
    int minDays(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int isLands=numOfIsLandsUtil(grid);
        if(isLands==0 || isLands>1){
            return 0;
        }else{
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        isLands=numOfIsLandsUtil(grid);
                        if(isLands==0 || isLands>1){
                            grid[i][j]=1;
                            return 1;
                        }
                        grid[i][j]=1;
                    }
                }
            }
        }
        return 2;
    }
};