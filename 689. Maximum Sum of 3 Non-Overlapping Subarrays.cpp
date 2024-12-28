// 689. Maximum Sum of 3 Non-Overlapping Subarrays
// Solved
// Hard
// Topics
// Companies
// Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

// Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

 

// Example 1:

// Input: nums = [1,2,1,2,6,7,5,1], k = 2
// Output: [0,3,5]
// Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
// We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
// Example 2:

// Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
// Output: [0,2,4]
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// 1 <= nums[i] < 216
// 1 <= k <= floor(nums.length / 3)
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 119.2K
// Submissions
// 209.4K
// Acceptance Rate
// 56.9%
// Topics
// Companies
// Similar Questions
// Discussion (112)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

// 2.3K


// 112





class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n=nums.size();
        vector<int> ksum(n-k+1, 0), L(n-3*k+1, -1);
        int maxKsum=ksum[0]=accumulate(nums.begin(), nums.begin()+k, 0);
        L[0]=0;
        for(int i=1; i<n-k+1; i++){
            ksum[i]=ksum[i-1]-nums[i-1]+nums[i+k-1];
            if (i>n-3*k) continue;
            if (maxKsum<ksum[i]){
                maxKsum=ksum[i];
                L[i]=i;
            }
            else L[i]=L[i-1];
        //    cout<<i<<"->L->"<<L[i]<<" maxKsum="<<maxKsum<<endl;
        }
        vector<int> R(n-3*k+1, -1);
        maxKsum=ksum.back();
        R.back()=n-k;
        for(int i=n-k-1; i>=2*k; i--){
            if (maxKsum<=ksum[i]){// multiple answers, return the lexico smallest one
                maxKsum=ksum[i];
                R[i-2*k]=i;
            }
            else R[i-2*k]=R[i+1-2*k];
        //    cout<<i-2*k<<"->R->"<<R[i-2*k]<<" maxKsum="<<maxKsum<<endl;
        }
        vector<int> ans(3,-1);
        int max3K=0;
        for(int i=0; i<=n-3*k; i++){
             int sum3K=ksum[L[i]]+ksum[i+k]+ksum[R[i]];
             if (sum3K> max3K){
                max3K=sum3K;
                ans={L[i], i+k, R[i]};
             }
        }
        return ans;  
    }
};
