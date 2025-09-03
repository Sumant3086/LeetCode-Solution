// 3027. Find the Number of Ways to Place People II
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// We define the right direction as positive x-axis (increasing x-coordinate) and the left direction as negative x-axis (decreasing x-coordinate). Similarly, we define the up direction as positive y-axis (increasing y-coordinate) and the down direction as negative y-axis (decreasing y-coordinate)

// You have to place n people, including Alice and Bob, at these points such that there is exactly one person at every point. Alice wants to be alone with Bob, so Alice will build a rectangular fence with Alice's position as the upper left corner and Bob's position as the lower right corner of the fence (Note that the fence might not enclose any area, i.e. it can be a line). If any person other than Alice and Bob is either inside the fence or on the fence, Alice will be sad.

// Return the number of pairs of points where you can place Alice and Bob, such that Alice does not become sad on building the fence.

// Note that Alice can only build a fence with Alice's position as the upper left corner, and Bob's position as the lower right corner. For example, Alice cannot build either of the fences in the picture below with four corners (1, 1), (1, 3), (3, 1), and (3, 3), because:

// With Alice at (3, 3) and Bob at (1, 1), Alice's position is not the upper left corner and Bob's position is not the lower right corner of the fence.
// With Alice at (1, 3) and Bob at (1, 1), Bob's position is not the lower right corner of the fence.

 

// Example 1:


// Input: points = [[1,1],[2,2],[3,3]]
// Output: 0
// Explanation: There is no way to place Alice and Bob such that Alice can build a fence with Alice's position as the upper left corner and Bob's position as the lower right corner. Hence we return 0. 
// Example 2:


// Input: points = [[6,2],[4,4],[2,6]]
// Output: 2
// Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
// - Place Alice at (4, 4) and Bob at (6, 2).
// - Place Alice at (2, 6) and Bob at (4, 4).
// You cannot place Alice at (2, 6) and Bob at (6, 2) because the person at (4, 4) will be inside the fence.
// Example 3:


// Input: points = [[3,1],[1,3],[1,1]]
// Output: 2
// Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
// - Place Alice at (1, 1) and Bob at (3, 1).
// - Place Alice at (1, 3) and Bob at (1, 1).
// You cannot place Alice at (1, 3) and Bob at (3, 1) because the person at (1, 1) will be on the fence.
// Note that it does not matter if the fence encloses any area, the first and second fences in the image are valid.
 

// Constraints:

// 2 <= n <= 1000
// points[i].length == 2
// -109 <= points[i][0], points[i][1] <= 109
// All points[i] are distinct.
 

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 44,470/73.9K
// Acceptance Rate
// 60.2%
// Topics
// icon
// Companies
// Hint 1
// Hint 2
// Hint 3
// Hint 4
// Similar Questions
// Discussion (139)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.

class Solution {
public:
    static bool cmp(const vector<int>& p, const vector<int>& q){
        return (p[0]==q[0])?p[1]<q[1]:p[0]>q[0];// order by (x, >)
    }
    static int numberOfPairs(vector<vector<int>>& P) {
        sort(P.begin(), P.end(), cmp);
        int n = P.size(), ans = 0;
        for(int i=0; i<n-1; i++){
            int y=INT_MAX, yi=P[i][1];
            for(int j = i+1; j<n; j++){
                const int yj=P[j][1];
                if (yj>=yi && y>yj){
                    ans++;
                    y=yj;
                    if (yi==yj) break;
                }
            }
        }
        return ans;
    }
}; 