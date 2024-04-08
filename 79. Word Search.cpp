
// Code
// Testcase
// Testcase
// Test Result
// 79. Word Search
// Solved
// Medium
// Topics
// Companies
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 

// Follow up: Could you use search pruning to make your solution faster with a larger board?


static auto _ = []() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 

    return 0; 
} ();
class Solution {
public:
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};

    bool backtrack(vector<vector<char>>& board, int r, int c, int idx, string& word) {
        
        if (idx >= word.size()) {
            return true; // Word found
        }
        if (r < 0 || r >= board.size() || c < 0 || c >= board[r].size() || board[r][c] != word[idx]) {
            return false; // Prune if out of bounds or mismatch
        }

        char ch = board[r][c];
        board[r][c] = '.'; // Mark the cell as visited

        for (int i = 0; i < 4; ++i) {
            int newRow = r + dir[i][0];
            int newCol = c + dir[i][1];
            if (backtrack(board, newRow, newCol, idx + 1, word)) {
                return true; // Recurse only if valid
            }
        }

        board[r][c] = ch; // Restore the original character
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (backtrack(board, i, j, 0, word)) {
                    return true; // Start search from each cell
                }
            }
        }
        return false; // Word not found on the board
    }
};
