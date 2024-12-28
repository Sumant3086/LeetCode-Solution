// 2940. Find Building Where Alice and Bob Can Meet
// Hard
// Topics
// Companies
// Hint
// You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.

// If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].

// You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi.

// Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.

 

// Example 1:

// Input: heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
// Output: [2,5,-1,5,2]
// Explanation: In the first query, Alice and Bob can move to building 2 since heights[0] < heights[2] and heights[1] < heights[2]. 
// In the second query, Alice and Bob can move to building 5 since heights[0] < heights[5] and heights[3] < heights[5]. 
// In the third query, Alice cannot meet Bob since Alice cannot move to any other building.
// In the fourth query, Alice and Bob can move to building 5 since heights[3] < heights[5] and heights[4] < heights[5].
// In the fifth query, Alice and Bob are already in the same building.  
// For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
// For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.
// Example 2:

// Input: heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
// Output: [7,6,-1,4,6]
// Explanation: In the first query, Alice can directly move to Bob's building since heights[0] < heights[7].
// In the second query, Alice and Bob can move to building 6 since heights[3] < heights[6] and heights[5] < heights[6].
// In the third query, Alice cannot meet Bob since Bob cannot move to any other building.
// In the fourth query, Alice and Bob can move to building 4 since heights[3] < heights[4] and heights[0] < heights[4].
// In the fifth query, Alice can directly move to Bob's building since heights[1] < heights[6].
// For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
// For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.

 

// Constraints:

// 1 <= heights.length <= 5 * 104
// 1 <= heights[i] <= 109
// 1 <= queries.length <= 5 * 104
// queries[i] = [ai, bi]
// 0 <= ai, bi <= heights.length - 1
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 39.4K
// Submissions
// 79.7K
// Acceptance Rate
// 49.5%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Hint 4
// Similar Questions
// Discussion (148)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

// 568


// 148




class Solution {
public:
    int n, sparseTable[50010][20], logValues[50010];

    int queryMaximum(int left, int right) {
        int k = logValues[right - left + 1];
        return max(sparseTable[left][k], sparseTable[right - (1 << k) + 1][k]);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        sparseTable[n][0] = 2e9;
        logValues[0] = -1;
        for (int i = 1; i <= n; i++) {
            logValues[i] = logValues[i >> 1] + 1;
        }
        for (int i = 0; i < n; i++) {
            sparseTable[i][0] = heights[i];
        }
        for (int i = 1; i < 20; i++) {
            for (int j = 0; j + (1 << i) - 1 <= n; j++) {
                sparseTable[j][i] = max(sparseTable[j][i - 1], sparseTable[j + (1 << (i - 1))][i - 1]);
            }
        }
        int numQueries = queries.size();
        vector<int> results(numQueries);
        for (int queryIndex = 0; queryIndex < numQueries; queryIndex++) {
            int left = queries[queryIndex][0], right = queries[queryIndex][1];
            if (left > right) swap(left, right);
            if (left == right) {
                results[queryIndex] = left;
                continue;
            }
            if (heights[right] > heights[left]) {
                results[queryIndex] = right;
                continue;
            }
            int maxHeight = max(heights[right], heights[left]);
            int low = right, high = n, mid;
            while (low < high) {
                mid = (low + high) >> 1;
                if (queryMaximum(right, mid) > maxHeight) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            results[queryIndex] = (low == n) ? -1 : low;
        }
        return results;
    }
};