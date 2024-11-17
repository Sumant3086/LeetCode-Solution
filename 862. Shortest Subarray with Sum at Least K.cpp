// 862. Shortest Subarray with Sum at Least K
// Solved
// Hard
// Topics
// Companies
// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [1], k = 1
// Output: 1
// Example 2:

// Input: nums = [1,2], k = 4
// Output: -1
// Example 3:

// Input: nums = [2,-1,2], k = 3
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 105
// -105 <= nums[i] <= 105
// 1 <= k <= 109

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 159.3K
// Submissions
// 515.4K
// Acceptance Rate
// 30.9%
// Topics
// Companies
// Similar Questions
// Discussion (128)

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res = INT_MAX;
        long long curSum = 0;
        deque<pair<long long, int>> q; 
        
        for (int r = 0; r < nums.size(); r++) {
            curSum += nums[r];
            
            if (curSum >= k) {
                res = min(res, r + 1);
            }
             
            while (!q.empty() && curSum - q.front().first >= k) {
                auto [prefix, endIdx] = q.front();
                q.pop_front();
                res = min(res, r - endIdx);
            } 
            while (!q.empty() && q.back().first > curSum) {
                q.pop_back();
            }
            q.push_back({curSum, r});
        }
        
        return res == INT_MAX ? -1 : res;
    }
};