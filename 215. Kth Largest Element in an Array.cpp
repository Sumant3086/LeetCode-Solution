// 215. Kth Largest Element in an Array
// Solved
// Medium
// Topics
// Companies
// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

 

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4
 

// Constraints:

// 1 <= k <= nums.length <= 105
// -104 <= nums[i] <= 104

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 2.8M
// Submissions
// 4.2M
// Acceptance Rate
// 67.6%
// Topics
// Array
// Divide and Conquer
// Sorting
// Heap (Priority Queue)
// Quickselect
// Companies
// Similar Questions
// Discussion (277)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            int n=nums.size();
            multiset<int>mst;
            for(int i:nums){
                mst.insert(i);
                if(mst.size()>k){
                    mst.erase(mst.begin());
                }
            } 
            return *mst.begin();
        }
    };