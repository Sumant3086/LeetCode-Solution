// 2461. Maximum Sum of Distinct Subarrays With Length K
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
// Explanation: The subarrays of nums with length 3 are:
// - [1,5,4] which meets the requirements and has a sum of 10.
// - [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is repeated.
// We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
// Example 2:

// Input: nums = [4,4,4], k = 3
// Output: 0
// Explanation: The subarrays of nums with length 3 are:
// - [4,4,4] which does not meet the requirements because the element 4 is repeated.
// We return 0 because no subarrays meet the conditions.
 

// Constraints:

// 1 <= k <= nums.length <= 105
// 1 <= nums[i] <= 105

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 165.3K
// Submissions
// 386.7K
// Acceptance Rate
// 42.8%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Similar Questions
// Discussion (189)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int freq[100001] = {0};
        int i = 0, j = 0, repeat = 0;
        ll sum = 0, maxsum = 0;
        while(j < n){
            sum += nums[j];
            if(++freq[nums[j]] == 2) ++repeat;
            while(i <= j && j-i+1 > k){
                sum -= nums[i];
                if(--freq[nums[i]]==1) --repeat;
                i++;
            }
            if(j-i+1 == k && !repeat){
                maxsum = max(maxsum, sum);
            }
            j++;
        }
        return maxsum;
    }
};
auto speedup = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();