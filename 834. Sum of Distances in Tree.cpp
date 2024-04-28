// 834. Sum of Distances in Tree
// Solved
// Hard
// Topics
// Companies
// There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

// You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

 

// Example 1:


// Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// Output: [8,12,6,10,10,10]
// Explanation: The tree is shown above.
// We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
// equals 1 + 1 + 2 + 2 + 2 = 8.
// Hence, answer[0] = 8, and so on.
// Example 2:


// Input: n = 1, edges = []
// Output: [0]
// Example 3:


// Input: n = 2, edges = [[1,0]]
// Output: [1,1]
 

// Constraints:

// 1 <= n <= 3 * 104
// edges.length == n - 1
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// The given input represents a valid tree.


class Solution {
private: 
    int dfs1(int node,int parent,vector<int> adj[],vector<int>& dp,vector<int>& ans) {
        int sum=0;
        int val=0;
        for(auto it:adj[node]){
            if(it!=parent){ 
                sum+=dfs1(it,node,adj,dp,ans);
                val+=ans[it];
            }
        }
        ans[node]=sum+val; 
        return dp[node]=sum+1;
    }
    void dfs2(int node,int parent,vector<int> adj[],vector<int>& dp,vector<int>& ans,int n){
        for(auto it:adj[node]){
            if(it!=parent){
                ans[it]+=ans[node]-(ans[it]+dp[it])+(n-dp[it]);
                dfs2(it,node,adj,dp,ans,n);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans(n, 0); // To store the sum of distances for each node
        vector<int>dp(n, 0); // To store the count of nodes in the subtree rooted at each node
        dfs1(0,-1,adj,dp,ans); // Perform the first DFS traversal
        dfs2(0,-1,adj,dp,ans,n); // Perform the second DFS traversal
        return ans; // Return the resulting array containing the sum of distances for each node
    }
};