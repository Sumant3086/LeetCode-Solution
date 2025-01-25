// 2948. Make Lexicographically Smallest Array by Swapping Elements
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed array of positive integers nums and a positive integer limit.

// In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

// Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

// An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.

 

// Example 1:

// Input: nums = [1,5,3,9,8], limit = 2
// Output: [1,3,5,8,9]
// Explanation: Apply the operation 2 times:
// - Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
// - Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
// We cannot obtain a lexicographically smaller array by applying any more operations.
// Note that it may be possible to get the same result by doing different operations.
// Example 2:

// Input: nums = [1,7,6,18,2,1], limit = 3
// Output: [1,6,7,18,1,2]
// Explanation: Apply the operation 3 times:
// - Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
// - Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
// - Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
// We cannot obtain a lexicographically smaller array by applying any more operations.
// Example 3:

// Input: nums = [1,7,28,19,10], limit = 3
// Output: [1,7,28,19,10]
// Explanation: [1,7,28,19,10] is the lexicographically smallest array we can obtain because we cannot apply the operation on any two indices.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 1 <= limit <= 109

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 59.6K
// Submissions
// 105.8K
// Acceptance Rate
// 56.3%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Hint 4
// Hint 5
// Similar Questions
// Discussion (165)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int threshold) {
        vector<pair<int, int>> valueIndexPairs;
        int size = arr.size();

        for (int i = 0; i < size; ++i) {
            valueIndexPairs.push_back({arr[i], i});
        }

        sort(valueIndexPairs.begin(), valueIndexPairs.end());

        vector<vector<pair<int, int>>> groupedPairs;
        groupedPairs.push_back({valueIndexPairs[0]});

        for (int i = 1; i < size; ++i) {
            if (valueIndexPairs[i].first - valueIndexPairs[i - 1].first <= threshold) {
                groupedPairs.back().push_back(valueIndexPairs[i]);
            } else {
                groupedPairs.push_back({valueIndexPairs[i]});
            }
        }

        for (const auto& group : groupedPairs) {
            vector<int> indices;
            for (const auto& [value, index] : group) {
                indices.push_back(index);
            }

            sort(indices.begin(), indices.end());

            for (size_t i = 0; i < indices.size(); ++i) {
                arr[indices[i]] = group[i].first;
            }
        }

        return arr;
    }
};
