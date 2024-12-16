// 3264. Final Array State After K Multiplication Operations I
// Solved
// Easy
// Topics
// Companies
// Hint
// You are given an integer array nums, an integer k, and an integer multiplier.

// You need to perform k operations on nums. In each operation:

// Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
// Replace the selected minimum value x with x * multiplier.
// Return an integer array denoting the final state of nums after performing all k operations.

 

// Example 1:

// Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

// Output: [8,4,6,5,6]

// Explanation:

// Operation	Result
// After operation 1	[2, 2, 3, 5, 6]
// After operation 2	[4, 2, 3, 5, 6]
// After operation 3	[4, 4, 3, 5, 6]
// After operation 4	[4, 4, 6, 5, 6]
// After operation 5	[8, 4, 6, 5, 6]
// Example 2:

// Input: nums = [1,2], k = 3, multiplier = 4

// Output: [16,8]

// Explanation:

// Operation	Result
// After operation 1	[4, 2]
// After operation 2	[4, 8]
// After operation 3	[16, 8]
 

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100
// 1 <= k <= 10
// 1 <= multiplier <= 5

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 95.8K
// Submissions
// 111.5K
// Acceptance Rate
// 86.0%
// Topics
// Companies
// Hint 1
// Hint 2
// Discussion (94)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

// 256


// 94





class Solution {
public:
    using int2 = pair<int, int>;
    static vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int2> heap(nums.size());
        for (int i = 0; i < nums.size(); i++) heap[i] = {nums[i], i};
        make_heap(heap.begin(), heap.end(), greater<>());
        while (k--) {
            pop_heap(heap.begin(), heap.end(), greater<>());
            heap.back().first *= multiplier;
            push_heap(heap.begin(), heap.end(), greater<>());
        }
        for (auto& [x, i] : heap) nums[i] = x;
        return nums;
    }
};

auto init = []() { ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); return 0; }();
