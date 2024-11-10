// 3097. Shortest Subarray With OR at Least K II
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an array nums of non-negative integers and an integer k.

// An array is called special if the bitwise OR of all of its elements is at least k.

// Return the length of the shortest special non-empty 
// subarray
//  of nums, or return -1 if no special subarray exists.

 

// Example 1:

// Input: nums = [1,2,3], k = 2

// Output: 1

// Explanation:

// The subarray [3] has OR value of 3. Hence, we return 1.

// Example 2:

// Input: nums = [2,1,8], k = 10

// Output: 3

// Explanation:

// The subarray [2,1,8] has OR value of 11. Hence, we return 3.

// Example 3:

// Input: nums = [1,2], k = 0

// Output: 1

// Explanation:

// The subarray [1] has OR value of 1. Hence, we return 1.

 

// Constraints:

// 1 <= nums.length <= 2 * 105
// 0 <= nums[i] <= 109
// 0 <= k <= 109

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 22.3K
// Submissions
// 60.9K
// Acceptance Rate
// 36.6%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Similar Questions
// Discussion (74)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int>cnt(32,0);
        int n=nums.size();
        int left=0;
        int right=0;
        int minLen=INT_MAX;
        while(right<n){
            updateBits(cnt,nums[right],1);
            while(left<=right && getVal(cnt)>=k){
                minLen=min(minLen,right-left+1);
                updateBits(cnt,nums[left],-1);
                left++;
            }
            right++;
        }
        return minLen==INT_MAX?-1:minLen;
    }
    private:
    void updateBits(vector<int>& cnt,int num,int val){
        for(int i=0;i<32;i++){
            if((num>>i) & 1){
                cnt[i]+=val;
            }
        }
    }
    int getVal(const vector<int>& cnt){
        int ans=0;
        for(int i=0;i<32;i++){
            if(cnt[i]>0){
                ans|=(1<<i);
            }
        }
    return ans;
    }
};