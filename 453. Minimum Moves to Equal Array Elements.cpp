// LeetCode Logo
// Problem List
// Debugging...
// Debugging...









// 1
// DCC Badge
// You missed 6 days this month. Buy Time Travel Ticket >

// avatar
// Avatar
// Sumant Yadav
// Access all features with our Premium subscription!
// myLists
// My Lists
// notebook
// Notebook
// submissions
// Submissions
// progress
// Progress
// points
// Points
// Try New Features
// Orders
// My Playgrounds
// Settings
// Appearance
// Sign Out
// Premium
// Description
// Editorial
// Editorial
// Solutions
// Solutions
// Submissions
// Submissions


// Code


// Testcase
// Test Result
// Test Result
// 453. Minimum Moves to Equal Array Elements
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment n - 1 elements of the array by 1.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 3
// Explanation: Only three moves are needed (remember each move increments two elements):
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
// Example 2:

// Input: nums = [1,1,1]
// Output: 0
 

// Constraints:

// n == nums.length
// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109
// The answer is guaranteed to fit in a 32-bit integer.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 198,482/343.6K
// Acceptance Rate
// 57.8%
// Topics
// icon
// Companies
// Similar Questions
// Discussion (43)

// Choose a type













// Read more








// Read more







// Read more

















// Read more






// Read more
// Copyright © 2025 LeetCode. All rights reserved.

// 2.7K


// 43


// 5 Online
// C++
// Auto





// 123456789
// class Solution {
// public:
//     int minMoves(vector<int>& nums) {
//         int n=nums.size();
//         int sum=0;
//         int mini=*min_element(nums.begin(),nums.end());
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//         }
//         return sum-mini*n;

// Saved
// Case 1
// Case 2

// nums =
// [1,2,3]
// Search questions



class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int mini=*min_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return sum-mini*n;
    }
};