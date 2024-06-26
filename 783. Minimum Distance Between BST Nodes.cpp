// 783. Minimum Distance Between BST Nodes
// Solved
// Easy
// Topics
// Companies
// Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

 

// Example 1:


// Input: root = [4,2,6,1,3]
// Output: 1
// Example 2:


// Input: root = [1,0,48,null,null,12,49]
// Output: 1
 

// Constraints:

// The number of nodes in the tree is in the range [2, 100].
// 0 <= Node.val <= 105
 

// Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
//      void helper(TreeNode* r,vector<int>&v){
//         if(r==NULL)return;
//         helper(r->left,v);
//         v.push_back(r->val);
//         helper(r->right,v);
//     }
//     int minDiffInBST(TreeNode* root){
//         vector<int>v;
//         helper(root,v);
//         int ans=INT_MAX;
//         for(int i=1;i<v.size();i++){
//             ans=min(ans,v[i]-v[i-1]);
//         }
//         return ans;
//     }
// };
//LPR in inorder
class Solution {
public:
    void inot(TreeNode* root, vector<int>& T){
        if(!root)
            return;
        inot(root->left,T);
        T.push_back(root->val);
        inot(root->right,T);
    }
    int minDiffInBST(TreeNode* root){
        vector<int>A;
        inot(root,A);
        int m=INT_MAX;
        for(int i=1;i<A.size();i++)
            m=min(m,abs(A[i]-A[i-1]));
        return m;
    }
};