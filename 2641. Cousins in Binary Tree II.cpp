// 2641. Cousins in Binary Tree II
// Solved
// Medium
// Topics
// Companies
// Hint
// Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Return the root of the modified tree.

// Note that the depth of a node is the number of edges in the path from the root node to it.

 

// Example 1:


// Input: root = [5,4,9,1,10,null,7]
// Output: [0,0,0,7,7,null,11]
// Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
// - Node with value 5 does not have any cousins so its sum is 0.
// - Node with value 4 does not have any cousins so its sum is 0.
// - Node with value 9 does not have any cousins so its sum is 0.
// - Node with value 1 has a cousin with value 7 so its sum is 7.
// - Node with value 10 has a cousin with value 7 so its sum is 7.
// - Node with value 7 has cousins with values 1 and 10 so its sum is 11.
// Example 2:


// Input: root = [3,1,2]
// Output: [0,0,0]
// Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
// - Node with value 3 does not have any cousins so its sum is 0.
// - Node with value 1 does not have any cousins so its sum is 0.
// - Node with value 2 does not have any cousins so its sum is 0.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 104



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
class Solution {
private:
    void dfs(TreeNode* parent, int level, vector<int>& sum) {
        int leftval = 0;
        int rightval = 0;
        
        if (parent->left != nullptr) leftval = parent->left->val;
        if (parent->right != nullptr) rightval = parent->right->val;

        if (parent->left != nullptr) {
            parent->left->val = sum[level + 1] - leftval - rightval;
            dfs(parent->left, level + 1, sum);
        }

        if (parent->right != nullptr) {
            parent->right->val = sum[level + 1] - leftval - rightval;
            dfs(parent->right, level + 1, sum);
        }
    }

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sum;

        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int k = Q.size();
            int s = 0;
            while (k--) {
                auto node = Q.front();
                Q.pop();
                s += node->val;
                if (node->left != nullptr) {
                    Q.push(node->left);
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                }
            }
            sum.push_back(s);
        }

        root->val = 0;
        dfs(root, 0, sum);
        return root;
    }
};