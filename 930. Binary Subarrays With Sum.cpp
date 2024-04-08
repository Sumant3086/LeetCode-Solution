// 930. Binary Subarrays With Sum
// Solved
// Medium
// Topics
// Companies
// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// nums[i] is either 0 or 1.
// 0 <= goal <= nums.length

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int res=0;
//         int sum=0;
//         unordered_map<int, int> prefixSumCount; 
//         prefixSumCount[0]=1; 
//         for(int i=0;i<nums.size();i++) {
//             sum+=nums[i];
//             res+=prefixSumCount[sum-goal]; 
//             prefixSumCount[sum]++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int l1=0,l2=0,r=0;
        int sum1=0,sum2=0;
        int ret=0;
        while (r<n){
            sum1+=nums[r];
            while(l1<=r && sum1>goal) {
                sum1-=nums[l1];
                l1++;
            }
            sum2+=nums[r];
            while(l2<=r && sum2>=goal){
                sum2-=nums[l2];
                l2++;
            }
            ret+=l2-l1;
            r++;
        }
        return ret;
    }
};