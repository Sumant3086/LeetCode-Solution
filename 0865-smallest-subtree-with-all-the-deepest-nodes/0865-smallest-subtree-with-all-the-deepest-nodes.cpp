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
public:
    pair<int,TreeNode*>dfs(TreeNode* root){
        if(!root)return {0,nullptr};
        auto L=dfs(root->left);
        auto R=dfs(root->right);
        if(L.first==R.first){
            return {L.first+1,root};
        }
        return (L.first>R.first)?
            make_pair(L.first+1,L.second):make_pair(R.first+1,R.second);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};