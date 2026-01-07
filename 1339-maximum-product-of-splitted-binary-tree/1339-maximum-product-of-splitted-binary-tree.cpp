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
    long long total=0,res=0;
    const long long mod=1e9+7;
    long long dfs(TreeNode* root){
        if(!root)return 0;
        int sum=root->val+dfs(root->left)+dfs(root->right);
        res=max(res,sum*(total-sum));
        return sum;
    }

    int maxProduct(TreeNode* root) {
        total=dfs(root);
        dfs(root);
        return res%mod;
    }
};