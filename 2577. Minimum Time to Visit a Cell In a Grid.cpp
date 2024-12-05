// 2577. Minimum Time to Visit a Cell In a Grid
// Hard
// Topics
// Companies
// Hint
// You are given a m x n matrix grid consisting of non-negative integers where grid[row][col] represents the minimum time required to be able to visit the cell (row, col), which means you can visit the cell (row, col) only when the time you visit it is greater than or equal to grid[row][col].

// You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell in the four directions: up, down, left, and right. Each move you make takes 1 second.

// Return the minimum time required in which you can visit the bottom-right cell of the matrix. If you cannot visit the bottom-right cell, then return -1.

 

// Example 1:



// Input: grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
// Output: 7
// Explanation: One of the paths that we can take is the following:
// - at t = 0, we are on the cell (0,0).
// - at t = 1, we move to the cell (0,1). It is possible because grid[0][1] <= 1.
// - at t = 2, we move to the cell (1,1). It is possible because grid[1][1] <= 2.
// - at t = 3, we move to the cell (1,2). It is possible because grid[1][2] <= 3.
// - at t = 4, we move to the cell (1,1). It is possible because grid[1][1] <= 4.
// - at t = 5, we move to the cell (1,2). It is possible because grid[1][2] <= 5.
// - at t = 6, we move to the cell (1,3). It is possible because grid[1][3] <= 6.
// - at t = 7, we move to the cell (2,3). It is possible because grid[2][3] <= 7.
// The final time is 7. It can be shown that it is the minimum time possible.
// Example 2:



// Input: grid = [[0,2,4],[3,2,1],[1,0,4]]
// Output: -1
// Explanation: There is no path from the top left to the bottom-right cell.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 2 <= m, n <= 1000
// 4 <= m * n <= 105
// 0 <= grid[i][j] <= 105
// grid[0][0] == 0
 


// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 77.5K
// Submissions
// 134.7K
// Acceptance Rate
// 57.5%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (112)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

using info = tuple<int, short, short>; // (time, i, j)
const static int d[5] = {0, 1, 0, -1, 0};
class Solution {
public:
    inline static bool isOutside(short i, short j, short n, short m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0]>1 && grid[0][1]>1)  return -1;// edge case
    
        short n = grid.size(), m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<info, vector<info>, greater<info>> pq;

        // Start at (0, 0) with time=0 
        pq.emplace(0, 0, 0);
        time[0][0] = 0;
        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();
        //    cout<<" t="<<int(t)<<" i="<<int(i)<<" j="<<int(j)<<endl;
            // reach the destination
            if (i == n - 1 && j == m - 1)
                return t;

            // Traverse all four directions
            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m)) continue;

                // minimum time to reach (r, s)
                int w=((grid[r][s]-t)&1)?0:1;
                int nextTime = max(t+1, grid[r][s]+w); // backward if neccessary

                // update if this path having quicker time
                if (nextTime < time[r][s]) {
                    time[r][s] = nextTime;
                    pq.emplace(nextTime, r, s);
                }
            }
        }

        return -1; // never reach
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();