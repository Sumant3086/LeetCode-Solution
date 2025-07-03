// 162. Find Peak Element
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
// Example 2:

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

// Constraints:

// 1 <= nums.length <= 1000
// -231 <= nums[i] <= 231 - 1
// nums[i] != nums[i + 1] for all valid i.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 1,979,400/4.3M
// Acceptance Rate
// 46.5%
// Topics
// icon
// Companies
// Similar Questions
// Discussion (369)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;while(start<end){
            int mid=(start+end)/2;
            if(nums[mid]<nums[mid+1]){
                start=mid+1;
            }else{
                end=mid;
            }
        }
        return start;
    }
};
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//            int n=nums.size();
//            for(int i=0;i<n;i++){
//             if((i==0 || nums[i]>nums[i-1]) && (i==n-1 || nums[i]>nums[i+1])){
//                 return i;
//             }
//         }
//         return -1; 
//     }
// };