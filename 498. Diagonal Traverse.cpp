// 498. Diagonal Traverse
// Medium
// Topics
// premium lock icon
// Companies
// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

// Example 1:


// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]
// Example 2:

// Input: mat = [[1,2],[3,4]]
// Output: [1,2,3,4]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// -105 <= mat[i][j] <= 105
 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 475,230/724.9K
// Acceptance Rate
// 65.6%
// Topics
// icon
// Companies
// Similar Questions
// Discussion (203)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>res;
        for(int d=0;d<m+n-1;d++){
            if(d%2==0){
                for(int i=min(d,m-1);i>=max(0,d-n+1);i--)
                    res.push_back(mat[i][d-i]);
            }else{
                for(int i=max(0,d-n+1);i<=min(d,m-1);i++)
                    res.push_back(mat[i][d-i]);
            }
        }
        return res;
    }
};