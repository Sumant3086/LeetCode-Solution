// 1072. Flip Columns For Maximum Number of Equal Rows
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an m x n binary matrix matrix.

// You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).

// Return the maximum number of rows that have all values equal after some number of flips.

 

// Example 1:

// Input: matrix = [[0,1],[1,1]]
// Output: 1
// Explanation: After flipping no values, 1 row has all values equal.
// Example 2:

// Input: matrix = [[0,1],[1,0]]
// Output: 2
// Explanation: After flipping values in the first column, both rows have equal values.
// Example 3:

// Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
// Output: 2
// Explanation: After flipping values in the first two columns, the last two rows have equal values.
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is either 0 or 1.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 64.7K
// Submissions
// 86.7K
// Acceptance Rate
// 74.6%
// Topics
// Companies
// Hint 1
// Discussion (119)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>freq;
        for(const auto& r:matrix){
            string ptrn;
            if(r[0]==0){
                for(int flip:r){
                    ptrn+=to_string(flip);
                }
            }else{
                for(int flip:r){
                    ptrn+=to_string(flip^1);
                }
            }
            freq[ptrn]++;
        }
        int maxF=0;
        for(const auto& pair:freq){
            maxF=max(maxF,pair.second);
        }
        return maxF;
    }
};