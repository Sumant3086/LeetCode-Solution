// 889. Construct Binary Tree from Preorder and Postorder Traversal
// Medium
// Topics
// Companies
// Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

// If there exist multiple answers, you can return any of them.

 

// Example 1:


// Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]
// Example 2:

// Input: preorder = [1], postorder = [1]
// Output: [1]
 

// Constraints:

// 1 <= preorder.length <= 30
// 1 <= preorder[i] <= preorder.length
// All the values of preorder are unique.
// postorder.length == preorder.length
// 1 <= postorder[i] <= postorder.length
// All the values of postorder are unique.
// It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 164.4K
// Submissions
// 215.5K
// Acceptance Rate
// 76.3%
// Topics
// Companies
// Discussion (109)

class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            stack<TreeNode*> nodes;
            TreeNode* root = new TreeNode(preorder[0]);
            nodes.push(root);
    
            int preIndex = 1, postIndex = 0;
    
            while (!nodes.empty()) {
                TreeNode* current = nodes.top();
    
                if (current->val == postorder[postIndex]) {
                    nodes.pop();
                    postIndex++;
                } else {
                    TreeNode* newNode = new TreeNode(preorder[preIndex++]);
                    if (!current->left) {
                        current->left = newNode;
                    } else {
                        current->right = newNode;
                    }
                    nodes.push(newNode);
                }
            }
            return root;
        }
    };