// 2257. Count Unguarded Cells in the Grid
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

// A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

// Return the number of unoccupied cells that are not guarded.

 

// Example 1:


// Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
// Output: 7
// Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
// There are a total of 7 unguarded cells, so we return 7.
// Example 2:


// Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
// Output: 4
// Explanation: The unguarded cells are shown in green in the above diagram.
// There are a total of 4 unguarded cells, so we return 4.
 

// Constraints:

// 1 <= m, n <= 105
// 2 <= m * n <= 105
// 1 <= guards.length, walls.length <= 5 * 104
// 2 <= guards.length + walls.length <= m * n
// guards[i].length == walls[j].length == 2
// 0 <= rowi, rowj < m
// 0 <= coli, colj < n
// All the positions in guards and walls are unique.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 30.6K
// Submissions
// 52.4K
// Acceptance Rate
// 58.5%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (52)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

// 517


// 52





class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int res = m * n - (int)walls.size() - (int)guards.size();
        int grid[m][n];
        memset(grid, 0, sizeof(grid));
        for (auto& wall : walls)
            grid[wall[0]][wall[1]] = 1;
        for (auto& guard : guards)
            grid[guard[0]][guard[1]] = 2;
        for (int r = 0; r < m; r++){
            for (int c = 0; c < n; c++){
                if (grid[r][c] != 2)
                    continue;
                for (int i = r - 1; i >= 0 && grid[i][c] <= 0; i--){
                    if (!grid[i][c]){
                        res--;
                        grid[i][c] = -1;
                    }
                }
                // down
                for (int i = r + 1; i < m && grid[i][c] <= 0; i++){
                    if (!grid[i][c]){
                        res--;
                        grid[i][c] = -1;
                    }
                }
                // left
                for (int i = c - 1; i >= 0 && grid[r][i] <= 0; i--){
                    if (!grid[r][i]){
                        grid[r][i] = -1;
                        res--;
                    }
                }
                // right
                for (int i = c + 1; i < n && grid[r][i] <= 0; i++){
                    if (!grid[r][i]){
                        res--;
                        grid[r][i] = -1;
                    }
                }
            }
        }
        return res;    
    }
};