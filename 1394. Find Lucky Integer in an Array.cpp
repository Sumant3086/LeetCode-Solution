// 1394. Find Lucky Integer in an Array
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

// Return the largest lucky integer in the array. If there is no lucky integer return -1.

 

// Example 1:

// Input: arr = [2,2,3,4]
// Output: 2
// Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
// Example 2:

// Input: arr = [1,2,2,3,3,3]
// Output: 3
// Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
// Example 3:

// Input: arr = [2,2,2,3,3]
// Output: -1
// Explanation: There are no lucky numbers in the array.
 

// Constraints:

// 1 <= arr.length <= 500
// 1 <= arr[i] <= 500

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 247,036/333.1K
// Acceptance Rate
// 74.2%
// Topics
// icon
// Companies
// Hint 1
// Hint 2
// Discussion (150)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i:arr){
            mp[i]++;
        }
        int res=-1;
        for(auto& [k,v]:mp){
            if(k==v){
                res=max(k,res);
            }
        }
        return res;
    }
};