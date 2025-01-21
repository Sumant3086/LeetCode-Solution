// 2661. First Completely Painted Row or Column
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

// Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

// Return the smallest index i at which either a row or a column will be completely painted in mat.

 

// Example 1:

// image explanation for example 1
// Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
// Output: 2
// Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
// Example 2:

// image explanation for example 2
// Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
// Output: 3
// Explanation: The second column becomes fully painted at arr[3].
 

// Constraints:

// m == mat.length
// n = mat[i].length
// arr.length == m * n
// 1 <= m, n <= 105
// 1 <= m * n <= 105
// 1 <= arr[i], mat[r][c] <= m * n
// All the integers of arr are unique.
// All the integers of mat are unique.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 119.6K
// Submissions
// 187.8K
// Acceptance Rate
// 63.7%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Hint 4
// Similar Questions
// Discussion (166)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int>rowC(n),colC(m);
        unordered_map<int,pair<int,int>>idx;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int num=mat[i][j];
                idx[num]={i,j};
            }
        }
        for(int k=0;k<arr.size();k++){
            int ele=arr[k];
            auto [i,j]=idx[ele];
            rowC[i]++;
            colC[j]++;
            if(rowC[i]==m || colC[j]==n){
                return k;
            }
        }
        return -1;
    }
};