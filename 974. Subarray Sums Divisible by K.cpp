// 974. Subarray Sums Divisible by K
// Solved
// Medium
// Topics
// Companies
// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
// Example 2:

// Input: nums = [5], k = 9
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -104 <= nums[i] <= 104
// 2 <= k <= 104


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixSum=0;
        int res=0;
        int n=nums.size();
        vector<int>modGroup(k,0);
        modGroup[0]=1;
        for(int num:nums){
            prefixSum=(prefixSum+num%k+k)%k;
            res+=modGroup[prefixSum];
            modGroup[prefixSum]++;
        }
        return res;
    }
};