// 2493. Divide Nodes Into the Maximum Number of Groups
// Hard
// Topics
// Companies
// Hint
// You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.

// You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

// Divide the nodes of the graph into m groups (1-indexed) such that:

// Each node in the graph belongs to exactly one group.
// For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
// Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.

 

// Example 1:


// Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
// Output: 4
// Explanation: As shown in the image we:
// - Add node 5 to the first group.
// - Add node 1 to the second group.
// - Add nodes 2 and 4 to the third group.
// - Add nodes 3 and 6 to the fourth group.
// We can see that every edge is satisfied.
// It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.
// Example 2:

// Input: n = 3, edges = [[1,2],[2,3],[3,1]]
// Output: -1
// Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
// It can be shown that no grouping is possible.
 

// Constraints:

// 1 <= n <= 500
// 1 <= edges.length <= 104
// edges[i].length == 2
// 1 <= ai, bi <= n
// ai != bi
// There is at most one edge between any pair of vertices.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 49.4K
// Submissions
// 77.7K
// Acceptance Rate
// 63.7%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Similar Questions
// Discussion (120)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
public:
    // Main function to calculate the maximum number of groups for the entire
    // graph
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(n);
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);

        // Build the adjacency list and apply Union-Find for each edge
        for (auto edge : edges) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
            Union(edge[0] - 1, edge[1] - 1, parent, depth);
        }

        unordered_map<int, int> numOfGroupsForComponent;

        // For each node, calculate the maximum number of groups for its
        // component
        for (int node = 0; node < n; node++) {
            int numberOfGroups = getNumberOfGroups(adjList, node, n);
            if (numberOfGroups == -1) return -1;  // If invalid split, return -1
            int rootNode = find(node, parent);
            numOfGroupsForComponent[rootNode] =
                max(numOfGroupsForComponent[rootNode], numberOfGroups);
        }

        // Calculate the total number of groups across all components
        int totalNumberOfGroups = 0;
        for (auto [rootNode, numberOfGroups] : numOfGroupsForComponent) {
            totalNumberOfGroups += numberOfGroups;
        }
        return totalNumberOfGroups;
    }

private:
    // Find the root of the given node in the Union-Find structure
    int find(int node, vector<int> &parent) {
        while (parent[node] != -1) node = parent[node];
        return node;
    }

    // Union operation to merge two sets
    void Union(int node1, int node2, vector<int> &parent, vector<int> &depth) {
        node1 = find(node1, parent);
        node2 = find(node2, parent);

        // If both nodes already belong to the same set, no action needed
        if (node1 == node2) return;

        // Union by rank (depth) to keep the tree balanced
        if (depth[node1] < depth[node2]) swap(node1, node2);
        parent[node2] = node1;

        // If the depths are equal, increment the depth of the new root
        if (depth[node1] == depth[node2]) depth[node1]++;
    }

    // Function to calculate the number of groups for a given component starting
    // from srcNode
    int getNumberOfGroups(vector<vector<int>> &adjList, int srcNode, int n) {
        queue<int> nodesQueue;
        vector<int> layerSeen(n, -1);
        nodesQueue.push(srcNode);
        layerSeen[srcNode] = 0;
        int deepestLayer = 0;

        // Perform BFS to calculate the number of layers (groups)
        while (!nodesQueue.empty()) {
            int numOfNodesInLayer = nodesQueue.size();
            for (int i = 0; i < numOfNodesInLayer; i++) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                for (int neighbor : adjList[currentNode]) {
                    // If neighbor hasn't been visited, assign it to the next
                    // layer
                    if (layerSeen[neighbor] == -1) {
                        layerSeen[neighbor] = deepestLayer + 1;
                        nodesQueue.push(neighbor);
                    } else {
                        // If the neighbor is already in the same layer, return
                        // -1 (invalid partition)
                        if (layerSeen[neighbor] == deepestLayer) {
                            return -1;
                        }
                    }
                }
            }
            deepestLayer++;
        }
        return deepestLayer;
    }
};