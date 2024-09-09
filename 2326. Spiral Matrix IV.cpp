
// Code


// Testcase
// Test Result
// Test Result
// 2326. Spiral Matrix IV
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given two integers m and n, which represent the dimensions of a matrix.

// You are also given the head of a linked list of integers.

// Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

// Return the generated matrix.

 

// Example 1:


// Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
// Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
// Explanation: The diagram above shows how the values are printed in the matrix.
// Note that the remaining spaces in the matrix are filled with -1.
// Example 2:


// Input: m = 1, n = 4, head = [0,1,2]
// Output: [[0,1,2,-1]]
// Explanation: The diagram above shows how the values are printed from left to right in the matrix.
// The last space in the matrix is set to -1.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int startingRow=0;
        int startingCol=0;
        int endingRow=m-1;
        int endingCol=n-1;
        vector<vector<int>>ans(m,vector<int>(n,-1));
        while(head){
            for(int i=startingCol;i<=endingCol && head;i++){
                ans[startingRow][i]=head->val;
                head=head->next;
            }
            startingRow++;
            for(int i=startingRow;i<=endingRow && head;i++){
                ans[i][endingCol]=head->val;
                head=head->next;
            }
            endingCol--;
            for(int i=endingCol;i>=startingCol && head;i--){
                ans[endingRow][i]=head->val;
                head=head->next;
            }
            endingRow--;
            for(int i=endingRow;i>=startingRow && head;i--){
                ans[i][startingCol]=head->val;
                head=head->next;
            }
            startingCol++;
        }
        return ans;
    }
};
static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();