// 3356. Zero Array Transformation II
// Medium
// Topics
// Companies
// Hint
// You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

// Each queries[i] represents the following action on nums:

// Decrement the value at each index in the range [li, ri] in nums by at most vali.
// The amount by which each value is decremented can be chosen independently for each index.
// A Zero Array is an array with all its elements equal to 0.

// Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

 

// Example 1:

// Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]

// Output: 2

// Explanation:

// For i = 0 (l = 0, r = 2, val = 1):
// Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
// The array will become [1, 0, 1].
// For i = 1 (l = 0, r = 2, val = 1):
// Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
// The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.
// Example 2:

// Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]

// Output: -1

// Explanation:

// For i = 0 (l = 1, r = 3, val = 2):
// Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
// The array will become [4, 1, 0, 0].
// For i = 1 (l = 0, r = 2, val = 1):
// Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
// The array will become [3, 0, 0, 0], which is not a Zero Array.
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 5 * 105
// 1 <= queries.length <= 105
// queries[i].length == 3
// 0 <= li <= ri < nums.length
// 1 <= vali <= 5

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 73.9K
// Submissions
// 180.3K
// Acceptance Rate
// 41.0%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (174)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canTransform(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> needed(nums.begin(), nums.end());
        vector<int> diff(n + 1, 0);
        
        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] += val;
            diff[r + 1] -= val;
        }

        int currDecrement = 0;
        for (int i = 0; i < n; i++) {
            currDecrement += diff[i];
            if (needed[i] > currDecrement)
                return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size(), ans = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canTransform(nums, queries, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
