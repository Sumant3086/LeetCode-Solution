// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
// Solved
// Hard
// Topics
// Companies
// Hint
// Alice and Bob have an undirected graph of n nodes and three types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can be traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

 

// Example 1:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// Output: 2
// Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
// Example 2:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// Output: 0
// Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
// Example 3:



// Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// Output: -1
// Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 

 

// Constraints:

// 1 <= n <= 105
// 1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
// edges[i].length == 3
// 1 <= typei <= 3
// 1 <= ui < vi <= n
// All tuples (typei, ui, vi) are distinct.

class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        DisjointSet ds1(n+1);
        DisjointSet ds2(n+1);
        int cnt = 0;
        for (auto& e : edges) {
            if (e[0] == 3) {
                if ((ds1.findUPar(e[1]) == ds1.findUPar(e[2])) &&
                    (ds2.findUPar(e[1]) == ds2.findUPar(e[2]))) {
                    cnt++;
                } else {
                    ds1.unionByRank(e[1], e[2]);
                    ds2.unionByRank(e[1], e[2]);
                }
            }
        }
        for (auto& e : edges) {
            if (e[0] == 1) {
                if ((ds1.findUPar(e[1]) == ds1.findUPar(e[2]))) {
                    cnt++;
                } else {
                    ds1.unionByRank(e[1], e[2]);
                }
            } else if (e[0] == 2) {
                if ((ds2.findUPar(e[1]) == ds2.findUPar(e[2]))) {
                    cnt++;
                } else {
                    ds2.unionByRank(e[1], e[2]);
                }
            }
        }
        int ct1=0;
        int ct2=0;
        for(int i=1; i<=n; i++)
        {
            if(ds1.findUPar(i)==i)
            {
                ct1++;
            }
            if(ds2.findUPar(i)==i)
            {
                ct2++;
            }
        }
        if(ct1>1 || ct2>1)
        {
            return -1;
        }
        
        return cnt;
    }
};