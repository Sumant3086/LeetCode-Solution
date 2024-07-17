// 94. Binary Tree Inorder Traversal
// Solved
// Easy
// Topics
// Companies
// Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

// Example 1:


// Input: root = [1,null,2,3]
// Output: [1,3,2]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 

// Follow up: Recursive solution is trivial, could you do it iteratively?

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
// class Solution {
// public:
// void helper(TreeNode* root,vector<int>& res){
//     if(!root)return;
//     helper(root->left,res);
//     res.push_back(root->val);
//     helper(root->right,res);
// }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>res;
//         helper(root,res);
//         return res;
//     }
// };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        vector<int>v=inorderTraversal(root->left);
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i]);
        }
        ans.push_back(root->val);
        v=inorderTraversal(root->right);
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i]);
        }
        return ans;
    }
};