// 1382. Balance a Binary Search Tree
// Solved
// Medium
// Topics
// Companies
// Hint
// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

// Example 1:


// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
// Example 2:


// Input: root = [2,1,3]
// Output: [2,1,3]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 105

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