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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inOdr;
        inOdrTraversal(root,inOdr);
        int size=inOdr.size();
        return createBalancedBST(inOdr,0,size-1);
    }
    private:
    void inOdrTraversal(TreeNode* root,vector<int>& inOdr){
        if(!root)return;
        inOdrTraversal(root->left,inOdr);
        inOdr.push_back(root->val);
        inOdrTraversal(root->right,inOdr);
    }
    TreeNode* createBalancedBST(const vector<int>& inOdr,int start,int end){
        if(start>end)return nullptr;
        int mid=(start+end)/2;
        TreeNode* leftSubtree=createBalancedBST(inOdr,start,mid-1);
        TreeNode* rightSubtree=createBalancedBST(inOdr,mid+1,end);
        return new TreeNode(inOdr[mid],leftSubtree,rightSubtree);
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();