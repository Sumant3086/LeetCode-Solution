// 54. Spiral Matrix
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        int count=0;
        int total=row * col;

        int sR=0;
        int sC=0;
        int eR=row-1;
        int eC=col-1;

        vector<int>ans;
        while(count<total){ 
            for(int idx=sC;count<total && idx<=eC;idx++){
               ans.push_back(matrix[sR][idx]);
               count++;
            }
            sR++; 
            for(int idx=sR;count<total && idx<=eR;idx++){
                ans.push_back(matrix[idx][eC]);
                count++;
            }
            eC--; 
            for(int idx=eC;count<total && idx>=sC;idx--){
                ans.push_back(matrix[eR][idx]);
                count++;
            }
            eR--;
            for (int idx=eR;count<total && idx>=sR;idx--){
                ans.push_back(matrix[idx][sC]);
                count++;
            }
            sC++;
        }
        return ans;
    }
};
