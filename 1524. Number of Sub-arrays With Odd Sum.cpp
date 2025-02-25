// 1524. Number of Sub-arrays With Odd Sum
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array of integers arr, return the number of subarrays with an odd sum.

// Since the answer can be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: arr = [1,3,5]
// Output: 4
// Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
// All sub-arrays sum are [1,4,9,3,8,5].
// Odd sums are [1,9,3,5] so the answer is 4.
// Example 2:

// Input: arr = [2,4,6]
// Output: 0
// Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
// All sub-arrays sum are [2,6,12,4,10,6].
// All sub-arrays have even sum and the answer is 0.
// Example 3:

// Input: arr = [1,2,3,4,5,6,7]
// Output: 16
 

// Constraints:

// 1 <= arr.length <= 105
// 1 <= arr[i] <= 100
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 85.6K
// Submissions
// 166.2K
// Acceptance Rate
// 51.5%
// Topics
// Array
// Math
// Dynamic Programming
// Prefix Sum
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (92)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int MOD=1e9+7;
            int oddC=0,evenC=1,prefSum=0,res=0;
            for(int i:arr){
                prefSum+=i;
                if(prefSum%2==0){
                    res=(res+oddC)%MOD;
                    evenC++;
                }
                if(prefSum%2!=0){
                    res=(res+evenC)%MOD;
                    oddC++;
                }
            }
            return res;
        }
    };
    
     static const int __ = [](){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return 0;
    }();