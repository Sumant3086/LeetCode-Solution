// 2054. Two Best Non-Overlapping Events
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

// Return this maximum sum.

// Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

 

// Example 1:


// Input: events = [[1,3,2],[4,5,2],[2,4,3]]
// Output: 4
// Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
// Example 2:

// Example 1 Diagram
// Input: events = [[1,3,2],[4,5,2],[1,5,5]]
// Output: 5
// Explanation: Choose event 2 for a sum of 5.
// Example 3:


// Input: events = [[1,5,3],[1,5,1],[6,6,5]]
// Output: 8
// Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
 

// Constraints:

// 2 <= events.length <= 105
// events[i].length == 3
// 1 <= startTimei <= endTimei <= 109
// 1 <= valuei <= 106
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 92.8K
// Submissions
// 150.8K
// Acceptance Rate
// 61.6%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (139)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(3, -1));
        return findEvents(events, 0, 0, dp);
    }
    // Recursive function to find the greatest sum for the pairs.
    int findEvents(vector<vector<int>>& events, int idx, int cnt,
                   vector<vector<int>>& dp) {
        if (cnt == 2 || idx >= events.size()) return 0;
        if (dp[idx][cnt] == -1) {
            int end = events[idx][1];
            int lo = idx + 1, hi = events.size() - 1;
            while (lo < hi) {
                int mid = lo + ((hi - lo) >> 1);
                if (events[mid][0] > end)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            int include =
                events[idx][2] + (lo < events.size() && events[lo][0] > end
                                      ? findEvents(events, lo, cnt + 1, dp)
                                      : 0);
            int exclude = findEvents(events, idx + 1, cnt, dp);
            dp[idx][cnt] = max(include, exclude);
        }
        return dp[idx][cnt];
    }
};