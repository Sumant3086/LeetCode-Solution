// 102. Binary Tree Level Order Traversal
// Solved
// Medium
// Topics
// Companies
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

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
// vector<vector<int>>res;
// void DFS(TreeNode* root,int level){
//     if(root==nullptr)return ;
//     if(level>=res.size()){
//         res.emplace_back();
//     }
//     res[level].push_back(root->val);
//     DFS(root->left,level+1);
//     DFS(root->right,level+1);
// }

//     vector<vector<int>> levelOrder(TreeNode* root) {
//         DFS(root,0);
//         return res;
//     }
// };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==nullptr)return res;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int levelSize=que.size();
            vector<int>currLevel;
            for(int i=0;i<levelSize;i++){
                TreeNode* node=que.front();
                que.pop();
                currLevel.push_back(node->val);
            if(node->left!=nullptr) que.push(node->left);
            if(node->right!=nullptr) que.push(node->right);
            }
            res.push_back(currLevel);
        }
        return res;
    }
};