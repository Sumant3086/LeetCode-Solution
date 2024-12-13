// 2593. Find Score of an Array After Marking All Elements
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an array nums consisting of positive integers.

// Starting with score = 0, apply the following algorithm:

// Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
// Add the value of the chosen integer to score.
// Mark the chosen element and its two adjacent elements if they exist.
// Repeat until all the array elements are marked.
// Return the score you get after applying the above algorithm.

 

// Example 1:

// Input: nums = [2,1,3,4,5,2]
// Output: 7
// Explanation: We mark the elements as follows:
// - 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
// - 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
// - 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
// Our score is 1 + 2 + 4 = 7.
// Example 2:

// Input: nums = [2,3,5,1,3,2]
// Output: 5
// Explanation: We mark the elements as follows:
// - 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
// - 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
// - 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
// Our score is 1 + 2 + 2 = 5.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 68.8K
// Submissions
// 109.4K
// Acceptance Rate
// 62.9%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (136)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

class Solution {
public:
    #define ll long long
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        ll sum = 0;
        vector<int> vis(nums.size());
        while (!pq.empty()) {
            if (vis[pq.top().second]) {
                pq.pop();
            } else {
                int ind = pq.top().second;
                sum += pq.top().first;
                pq.pop();
                vis[ind] = 1;
                if (ind - 1 >= 0) vis[ind - 1] = 1;
                if (ind + 1 < n) vis[ind + 1] = 1;
            }
        }
        return sum;
    }
};