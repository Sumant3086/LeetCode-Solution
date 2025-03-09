// 3208. Alternating Groups II
// Medium
// Topics
// Companies
// Hint
// There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

// colors[i] == 0 means that tile i is red.
// colors[i] == 1 means that tile i is blue.
// An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

// Return the number of alternating groups.

// Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

 

// Example 1:

// Input: colors = [0,1,0,1,0], k = 3

// Output: 3

// Explanation:



// Alternating groups:



// Example 2:

// Input: colors = [0,1,0,0,1,0,1], k = 6

// Output: 2

// Explanation:



// Alternating groups:



// Example 3:

// Input: colors = [1,1,0,1], k = 4

// Output: 0

// Explanation:



 

// Constraints:

// 3 <= colors.length <= 105
// 0 <= colors[i] <= 1
// 3 <= k <= colors.length
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 98.1K
// Submissions
// 172.7K
// Acceptance Rate
// 56.8%
// Topics
// Companies
// Hint 1
// Hint 2
// Discussion (142)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

// 544


// 142





class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n=colors.size();
            int count=0;
            int left=0;
            for(int right=0;right<n+k-1;right++){
                if(right>0 && colors[right%n]==colors[(right-1)%n]){
                    left=right;
                }
                if(right-left+1>=k){
                    count++;
                }
            }
            return count;
        }
    };
    // class Solution {
    // public:
    //     int numberOfAlternatingGroups(vector<int>& colors, int k) {
    //         int n=colors.size();
    //         if(k>n)return 0;
    //         vector<bool>fine(n,false);
    //         for(int i=0;i<n;i++){
    //             int next=(i+1)%n;
    //             if(colors[i]!=colors[next]){
    //                 fine[i]=true;
    //             }
    //         }
    //         int count=0;
    //         int len=0;
    //         for(int i=0;i<n+k+1;i++){
    //             int idx=i%n;
    //             if (fine[idx]){
    //                 len++;
    //                 if(len>=k){
    //                     count++;
    //                 }
    //             }else{
    //                 len=0;
    //             }
    //         }
    //         return count;
    //     }
    // };