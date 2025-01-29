// 684. Redundant Connection
// Medium
// Topics
// Companies
// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

// Example 1:


// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]
// Example 2:


// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]
 

// Constraints:

// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ai < bi <= edges.length
// ai != bi
// There are no repeated edges.
// The given graph is connected.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 480.9K
// Submissions
// 736.5K
// Acceptance Rate
// 65.3%
// Topics
// Companies
// Similar Questions
// Discussion (112)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
    class DSU {
    private:
        int N;
        vector<int> size;
        vector<int> representative;

    public:
        // Initialize DSU class, size of each component will be one and each
        // node will be representative of it's own.
        DSU(int N) {
            this->N = N;

            for (int node = 0; node < N; node++) {
                size.push_back(1);
                representative.push_back(node);
            }
        }

        // Returns the ultimate representative of the node.
        int find(int node) {
            if (representative[node] == node) {
                return node;
            }

            return representative[node] = find(representative[node]);
        }

        // Returns true if nodeOne and nodeTwo belong to different component and
        // update the representatives accordingly, otherwise returns false.
        bool doUnion(int nodeOne, int nodeTwo) {
            nodeOne = find(nodeOne);
            nodeTwo = find(nodeTwo);

            if (nodeOne == nodeTwo) {
                return 0;
            } else {
                if (size[nodeOne] > size[nodeTwo]) {
                    representative[nodeTwo] = nodeOne;
                    size[nodeOne] += size[nodeTwo];
                } else {
                    representative[nodeOne] = nodeTwo;
                    size[nodeTwo] += size[nodeOne];
                }
                return 1;
            }
        }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        DSU dsu(N);
        for (auto edge : edges) {
            // If union returns false, we know the nodes are already connected
            // and hence we can return this edge.
            if (!dsu.doUnion(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }

        return {};
    }
};