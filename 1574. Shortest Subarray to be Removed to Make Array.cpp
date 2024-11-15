// 1574. Shortest Subarray to be Removed to Make Array Sorted
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

// Return the length of the shortest subarray to remove.

// A subarray is a contiguous subsequence of the array.

 

// Example 1:

// Input: arr = [1,2,3,10,4,2,3,5]
// Output: 3
// Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
// Another correct solution is to remove the subarray [3,10,4].
// Example 2:

// Input: arr = [5,4,3,2,1]
// Output: 4
// Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].
// Example 3:

// Input: arr = [1,2,3]
// Output: 0
// Explanation: The array is already non-decreasing. We do not need to remove any elements.
 

// Constraints:

// 1 <= arr.length <= 105
// 0 <= arr[i] <= 109

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 99.9K
// Submissions
// 194.3K
// Acceptance Rate
// 51.4%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (107)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), l{0}, r = n - 1;
        while (l + 1 < n && arr[l] <= arr[l + 1]) ++l;
        if (l == n - 1) return 0;
        while (r > l && arr[r - 1] <= arr[r]) --r;
        int res = min(n - l - 1, r);
        for (int i{0}, j = r; i <= l && j < n; ) 
            arr[i] <= arr[j] ? res = min(res, j - i++ - 1) : ++j;
        return res;
    }
};