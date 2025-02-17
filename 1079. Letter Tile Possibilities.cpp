// 1079. Letter Tile Possibilities
// Medium
// Topics
// Companies
// Hint
// You have n  tiles, where each tile has one letter tiles[i] printed on it.

// Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

 

// Example 1:

// Input: tiles = "AAB"
// Output: 8
// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
// Example 2:

// Input: tiles = "AAABBC"
// Output: 188
// Example 3:

// Input: tiles = "V"
// Output: 1
 

// Constraints:

// 1 <= tiles.length <= 7
// tiles consists of uppercase English letters.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 194.6K
// Submissions
// 236.3K
// Acceptance Rate
// 82.3%
// Topics
// Hash Table
// String
// Backtracking
// Counting
// Companies
// Hint 1
// Discussion (108)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

// 2.9K


// 108




class Solution {
    public:
    int helper(unordered_map<char,int>& freq){
        int total=0;
        for(auto &[ch,count]:freq){
            if(count>0){
                total++;
                count--;
                total+=helper(freq);
                count++;
            }
        }
        return total;
    }
    
        int numTilePossibilities(string tiles) {
            unordered_map<char,int>freq;
            for(char c:tiles)freq[c]++;
            return helper(freq);
        }
    };