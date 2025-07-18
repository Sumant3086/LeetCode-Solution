// 1857. Largest Color Value in a Directed Graph
// Solved
// Hard
// Topics
// Companies
// Hint
// There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

// You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

// A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

// Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

 

// Example 1:



// Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
// Output: 3
// Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
// Example 2:



// Input: colors = "a", edges = [[0,0]]
// Output: -1
// Explanation: There is a cycle from 0 to 0.
 

// Constraints:

// n == colors.length
// m == edges.length
// 1 <= n <= 105
// 0 <= m <= 105
// colors consists of lowercase English letters.
// 0 <= aj, bj < n

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 123K
// Submissions
// 216.4K
// Acceptance Rate
// 56.8%
// Topics
// Companies
// Hint 1
// Hint 2
// Discussion (117)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
public:
    int dfs(int node, string &colors, vector<vector<int>> &adj, vector<vector<int>> &count, vector<int> &vis) {
        if (!vis[node]) {
            vis[node] = 1;
            for (int next : adj[node]) {
                if (dfs(next, colors, adj, count, vis) == INT_MAX)
                    return INT_MAX;
                for (int c = 0; c < 26; c++)
                    count[node][c] = max(count[node][c], count[next][c]);
            }
            ++count[node][colors[node] - 'a'];
            vis[node] = 2;
        }
        return vis[node] == 2 ? count[node][colors[node] - 'a'] : INT_MAX;
    }

    int largestPathValue(string colors, vector<vector<int>> &edges) {
        int n = colors.size();
        vector<vector<int>> adj(n), count(n, vector<int>(26));
        vector<int> vis(n);
        for (auto &e : edges)
            adj[e[0]].push_back(e[1]);
        int ans = 0;
        for (int i = 0; i < n && ans != INT_MAX; i++)
            ans = max(ans, dfs(i, colors, adj, count, vis));
        return ans == INT_MAX ? -1 : ans;
    }
};