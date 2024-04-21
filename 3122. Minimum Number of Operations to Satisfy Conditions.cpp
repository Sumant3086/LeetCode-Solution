// 3122. Minimum Number of Operations to Satisfy Conditions
// Solved
// Medium
// Companies
// Hint
// You are given a 2D matrix grid of size m x n. In one operation, you can change the value of any cell to any non-negative number. You need to perform some operations such that each cell grid[i][j] is:

// Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
// Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).
// Return the minimum number of operations needed.

 

// Example 1:

// Input: grid = [[1,0,2],[1,0,2]]

// Output: 0

// Explanation:



// All the cells in the matrix already satisfy the properties.

// Example 2:

// Input: grid = [[1,1,1],[0,0,0]]

// Output: 3

// Explanation:



// The matrix becomes [[1,0,1],[1,0,1]] which satisfies the properties, by doing these 3 operations:

// Change grid[1][0] to 1.
// Change grid[0][1] to 0.
// Change grid[1][2] to 1.
// Example 3:

// Input: grid = [[1],[2],[3]]

// Output: 2

// Explanation:



// There is a single column. We can change the value to 1 in each cell using 2 operations.

 

// Constraints:

// 1 <= n, m <= 1000
// 0 <= grid[i][j] <= 9

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 7.1K
// Submissions
// 21K
// Acceptance Rate
// 33.7%
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (24)

// Choose a type















class Solution {
public:
    int minimumOperations(vector<vector<int>>& candy) {
        const int m=candy.size(),n=candy[0].size();
        vector<int>dp(10);
        for(int j=0;j<n;++j){
            vector<int>v(10);
            for(int i=0;i<m;++i){
               ++v[candy[i][j]];
            }
            vector<int> temp(10,INT_MAX);
            for(int i=0;i<10;++i) {
                int t=INT_MAX;
                for(int j=0;j<10;++j){
                    if(j!=i){
                        t=min(t,dp[j]);
                    }
                }
                temp[i]=min(temp[i],t+m-v[i]);
            }
            dp=temp;
        }
        return *min_element(dp.begin(),dp.end());
    }
};
