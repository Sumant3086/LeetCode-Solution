// 104. Maximum Depth of Binary Tree
// Solved
// Easy
// Topics
// Companies
// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: 3
// Example 2:

// Input: root = [1,null,2]
// Output: 2
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -100 <= Node.val <= 100
// Seen this question in a real interview before?
// 1/5

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

//  class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root) return 0;
//         int mLeft=maxDepth(root->left);
//         int mRight=maxDepth(root->right);
//         return max(mLeft,mRight)+1;
        
//     }
// }; 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        queue<TreeNode*>que;
        que.push(root);
        int depth=0;
        while(!que.empty()){
            int levelSize=que.size();
            vector<int>currLevel;
            for(int i=0;i<levelSize;i++){
                TreeNode* node=que.front();
                que.pop();
                // currLevel.push_back(node->val);
            if(node->left!=nullptr) que.push(node->left);
            if(node->right!=nullptr) que.push(node->right);
            }
            // res.push_back(currLevel);
            depth++;
        }
        return depth;
    }
};