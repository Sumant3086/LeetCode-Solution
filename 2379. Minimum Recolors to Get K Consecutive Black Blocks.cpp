// 2379. Minimum Recolors to Get K Consecutive Black Blocks
// Easy
// Topics
// Companies
// Hint
// You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

// You are also given an integer k, which is the desired number of consecutive black blocks.

// In one operation, you can recolor a white block such that it becomes a black block.

// Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

 

// Example 1:

// Input: blocks = "WBBWWBBWBW", k = 7
// Output: 3
// Explanation:
// One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
// so that blocks = "BBBBBBBWBW". 
// It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
// Therefore, we return 3.
// Example 2:

// Input: blocks = "WBWBBBW", k = 2
// Output: 0
// Explanation:
// No changes need to be made, since 2 consecutive black blocks already exist.
// Therefore, we return 0.
 

// Constraints:

// n == blocks.length
// 1 <= n <= 100
// blocks[i] is either 'W' or 'B'.
// 1 <= k <= n

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 122.2K
// Submissions
// 187.1K
// Acceptance Rate
// 65.3%
// Topics
// String
// Sliding Window
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (81)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int white=count(blocks.begin(),blocks.begin()+k,'W');
            int minOps=white;
            for(int i=k;i<blocks.size();i++){
                white+=(blocks[i]=='W')-(blocks[i-k]=='W');
                minOps=min(minOps,white);
            }
            return minOps;
        }
    };