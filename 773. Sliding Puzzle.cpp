// 773. Sliding Puzzle
// Hard
// Topics
// Companies
// Hint
// On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

// The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

// Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

 

// Example 1:


// Input: board = [[1,2,3],[4,0,5]]
// Output: 1
// Explanation: Swap the 0 and the 5 in one move.
// Example 2:


// Input: board = [[1,2,3],[5,4,0]]
// Output: -1
// Explanation: No number of moves will make the board solved.
// Example 3:


// Input: board = [[4,1,2],[5,0,3]]
// Output: 5
// Explanation: 5 is the smallest number of moves that solves the board.
// An example path:
// After move 0: [[4,1,2],[5,0,3]]
// After move 1: [[4,1,2],[0,5,3]]
// After move 2: [[0,1,2],[4,5,3]]
// After move 3: [[1,0,2],[4,5,3]]
// After move 4: [[1,2,0],[4,5,3]]
// After move 5: [[1,2,3],[4,5,0]]
 

// Constraints:

// board.length == 2
// board[i].length == 3
// 0 <= board[i][j] <= 5
// Each value board[i][j] is unique.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 135.7K
// Submissions
// 194.1K
// Acceptance Rate
// 69.9%
// Topics
// Companies
// Hint 1
// Discussion (95)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int rowS = 2;
        int colS = 3;
        string compare = "";
        string target = "123450";
        
        for (int i = 0; i < rowS; i++) {
            for (int j = 0; j < colS; j++) {
                compare += to_string(board[i][j]);
            }
        }
        
        queue<pair<string, int>> q;
        q.push({compare, 0});
        unordered_set<string> visited;
        visited.insert(compare);
        
        vector<vector<int>> moves = {
            {1, 3},          // Index 0 can move to 1 or 3
            {0, 2, 4},       // Index 1 can move to 0, 2, or 4
            {1, 5},          // Index 2 can move to 1 or 5
            {0, 4},          // Index 3 can move to 0 or 4
            {1, 3, 5},       // Index 4 can move to 1, 3, or 5
            {2, 4}           // Index 5 can move to 2 or 4
        };

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();
            
            if (curr == target) {
                return steps;
            }
            
            int zeroIdx = curr.find('0');  // Locate the '0' index
            
            for (int move : moves[zeroIdx]) {
                string temp = curr;
                swap(temp[zeroIdx], temp[move]);
                
                if (visited.find(temp) == visited.end()) {
                    visited.insert(temp);
                    q.push({temp, steps + 1});
                }
            }
        }
        
        return -1;
    }
};
