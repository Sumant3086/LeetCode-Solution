// 1861. Rotating the Box
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

// A stone '#'
// A stationary obstacle '*'
// Empty '.'
// The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

// It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

// Return an n x m matrix representing the box after the rotation described above.

 

// Example 1:



// Input: box = [["#",".","#"]]
// Output: [["."],
//          ["#"],
//          ["#"]]
// Example 2:



// Input: box = [["#",".","*","."],
//               ["#","#","*","."]]
// Output: [["#","."],
//          ["#","#"],
//          ["*","*"],
//          [".","."]]
// Example 3:



// Input: box = [["#","#","*",".","*","."],
//               ["#","#","#","*",".","."],
//               ["#","#","#",".","#","."]]
// Output: [[".","#","#"],
//          [".","#","#"],
//          ["#","#","*"],
//          ["#","*","."],
//          ["#",".","*"],
//          ["#",".","."]]
 

// Constraints:

// m == box.length
// n == box[i].length
// 1 <= m, n <= 500
// box[i][j] is either '#', '*', or '.'.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 117.6K
// Submissions
// 151.6K
// Acceptance Rate
// 77.6%
// Topics
// Companies
// Hint 1
// Hint 2
// Discussion (128)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        for (auto& row : box) {
            int dropPos = n - 1;
            
            for (int currPos = n - 1; currPos >= 0; currPos--) {
                if (row[currPos] == '*') {
                    dropPos = currPos - 1;
                }
                else if (row[currPos] == '#') {
                    swap(row[dropPos], row[currPos]);
                    dropPos--;
                }
            }
        }
        
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - 1 - i] = box[i][j];
            }
        }
        
        return rotatedBox;
    }
};