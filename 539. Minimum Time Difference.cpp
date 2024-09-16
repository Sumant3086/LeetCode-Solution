// 539. Minimum Time Difference
// Solved
// Medium
// Topics
// Companies
// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

// Example 1:

// Input: timePoints = ["23:59","00:00"]
// Output: 1
// Example 2:

// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0
 

// Constraints:

// 2 <= timePoints.length <= 2 * 104
// timePoints[i] is in the format "HH:MM".
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 235.4K
// Submissions
// 389.6K
// Acceptance Rate
// 60.4%
// Topics
// Array
// Math
// String
// Sorting
// Companies
// Similar Questions
// Discussion (109)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

// 2.3K


// 109





class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int>minutes(n);
        for(int i=0;i<n;i++){
            string time=timePoints[i];
            string hourStr=time.substr(0,2);
            string minStr=time.substr(3);
            int hourInt=stoi(hourStr);
            int minInt=stoi(minStr);
            minutes[i]=hourInt*60+minInt;
        }
        sort(begin(minutes),end(minutes));
        int res=INT_MAX;
        for(int i=1;i<n;i++){
            res=min(res,minutes[i]-minutes[i-1]);
        }
        return min(res,(24*60-minutes[n-1])+minutes[0]);
    }
};