// 2196. Create Binary Tree From Descriptions
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.

// The test cases will be generated such that the binary tree is valid.

 

// Example 1:


// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.
// Example 2:


// Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// Output: [1,2,null,null,3,4]
// Explanation: The root node is the node with value 1 since it has no parent.
// The resulting binary tree is shown in the diagram.
 

// Constraints:

// 1 <= descriptions.length <= 104
// descriptions[i].length == 3
// 1 <= parenti, childi <= 105
// 0 <= isLefti <= 1
// The binary tree described by descriptions is valid.

// class Solution {
// public:
//     TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
//         // Step 1: Organize data
//         unordered_map<int, vector<pair<int, bool>>> parentToChildren;
//         unordered_set<int> allNodes;
//         unordered_set<int> children;

//         for (auto& desc : descriptions) {
//             int parent = desc[0];
//             int child = desc[1];
//             bool isLeft = desc[2];

//             parentToChildren[parent].push_back({child, isLeft});
//             allNodes.insert(parent);
//             allNodes.insert(child);
//             children.insert(child);
//         }

//         // Step 2: Find the root
//         int rootVal = 0;
//         for (int node : allNodes) {
//             if (!children.contains(node)) {
//                 rootVal = node;
//                 break;
//             }
//         }

//         // Step 3 & 4: Build the tree using DFS
//         return dfs(parentToChildren, rootVal);
//     }

// private:
//     TreeNode* dfs(unordered_map<int, vector<pair<int, bool>>>& parentToChildren,
//                   int val) {
//         // Create new TreeNode for current value
//         TreeNode* node = new TreeNode(val);

//         // If current node has children, recursively build them
//         if (parentToChildren.find(val) != parentToChildren.end()) {
//             for (auto& child_info : parentToChildren[val]) {
//                 int child = child_info.first;
//                 bool isLeft = child_info.second;

//                 // Attach child node based on isLeft flag
//                 if (isLeft) {
//                     node->left = dfs(parentToChildren, child);
//                 } else {
//                     node->right = dfs(parentToChildren, child);
//                 }
//             }
//         }

//         return node;
//     }
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 TreeNode* nodes[100001];
 int parent[100001];
 int vals[100001];
 int valCnt = 0;
 TreeNode pool[10001];
 int poolIdx;
 TreeNode* newNode(int _val) {
    TreeNode* node = &pool[poolIdx++];
    node->val = _val;
    node->left = node->right = nullptr;
    return node;
 }

 TreeNode* findNode(int _val) {
    if (!nodes[_val]) {
        nodes[_val] = newNode(_val);
        vals[valCnt++] = _val;
    }
    return nodes[_val];
 }

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        for (int i = 0; i < valCnt; ++i) {
            nodes[vals[i]] = nullptr;
            parent[vals[i]] = 0;
        }
        valCnt = 0;
        poolIdx = 0;
        TreeNode* curr;
        TreeNode* p;
        int n = descriptions.size();
        for (int i = 0; i < n; ++i) {
            p = findNode(descriptions[i][0]);
            curr = findNode(descriptions[i][1]);
            parent[descriptions[i][1]] = descriptions[i][0];
            if (descriptions[i][2]) {
                p->left = curr;
            } else {
                p->right = curr;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!parent[descriptions[i][0]]) {
                return nodes[descriptions[i][0]];
            }
        }
        return nullptr;
    }
};