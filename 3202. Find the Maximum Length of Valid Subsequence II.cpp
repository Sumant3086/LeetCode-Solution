// 3202. Find the Maximum Length of Valid Subsequence II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums and a positive integer k.
// A subsequence sub of nums with length x is called valid if it satisfies:

// (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
// Return the length of the longest valid subsequence of nums.
 

// Example 1:

// Input: nums = [1,2,3,4,5], k = 2

// Output: 5

// Explanation:

// The longest valid subsequence is [1, 2, 3, 4, 5].

// Example 2:

// Input: nums = [1,4,2,3,1,4], k = 3

// Output: 4

// Explanation:

// The longest valid subsequence is [1, 4, 1, 4].

 

// Constraints:

// 2 <= nums.length <= 103
// 1 <= nums[i] <= 107
// 1 <= k <= 103

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 79,392/141.9K
// Acceptance Rate
// 55.9%
// Topics
// icon
// Companies
// Hint 1
// Hint 2
// Hint 3
// Similar Questions
// Discussion (120)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        int res=1;
        vector<unordered_map<int,int>>dp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                // cout<<nums[j]<<" "<<nums[i]<<" ";
                int val=(nums[i]+nums[j])%k;
                int len=2;
                if(dp[j].count(val)){
                    len=dp[j][val]+1;
                }
                dp[i][val]=max(dp[i][val],len);
                res=max(res,dp[i][val]);
            }
            // cout<<endl;
        }
        return res;
    }
};
// class Solution {
// public:
//     int maximumLength(vector<int>& nums, int k) {
//         int n=nums.size();
//         int maxL=0;
//         for(int i=0;i<(1<<n);i++){
//             vector<int>arr;
//             for(int j=0;j<n;j++){
//                 if(i & (1<<j)){
//                     arr.push_back(nums[j]);
//                 }
//             }
//             if(arr.size()<2)continue;
//             int val=(arr[0]+arr[1])%k;
//             bool valid=true;
//             for(int i=1;i<arr.size();i++){
//                 if((arr[i-1]+arr[i])%k!=val){
//                     valid=false;
//                     break;
//                 }
//             }
//             if(valid){
//                 maxL=max(maxL,(int)arr.size());
//             }
//         }
//         return maxL;
//     }
// };


class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long> leftSum(3 * n, 0), rightSum(3 * n + 1, 0);
        
        priority_queue<int> maxHeap;
        long long left = 0;
        for (int i = 0; i < 2 * n; ++i) {
            left += nums[i];
            maxHeap.push(nums[i]);
            if (maxHeap.size() > n) {
                left -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == n) leftSum[i] = left;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long right = 0;
        for (int i = 3 * n - 1; i >= n; --i) {
            right += nums[i];
            minHeap.push(nums[i]);
            if (minHeap.size() > n) {
                right -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == n) rightSum[i] = right;
        }

        long long ans = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            ans = min(ans, leftSum[i] - rightSum[i + 1]);
        }
        return ans;
    }
};
