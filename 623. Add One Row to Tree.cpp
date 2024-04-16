// 623. Add One Row to Tree
// Solved
// Medium
// Topics
// Companies
// Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

// Note that the root node is at depth 1.

// The adding rule is:

// Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
// cur's original left subtree should be the left subtree of the new left subtree root.
// cur's original right subtree should be the right subtree of the new right subtree root.
// If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
 

// Example 1:


// Input: root = [4,2,6,3,1,5], val = 1, depth = 2
// Output: [4,1,1,2,null,null,6,3,1,5]
// Example 2:


// Input: root = [4,2,null,3,1], val = 1, depth = 3
// Output: [4,2,null,1,1,3,null,null,1]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// The depth of the tree is in the range [1, 104].
// -100 <= Node.val <= 100
// -105 <= val <= 105
// 1 <= depth <= the depth of tree + 1


// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* add(TreeNode* root, int val, int depth,int curr) {
//         if(root==NULL) return NULL;
//         if(curr==depth-1){
//             TreeNode* leftTemp=root->left;
//             TreeNode* rightTemp=root->right;

//             root->left=new TreeNode(val);
//             root->right=new TreeNode(val);

//             root->left->left=leftTemp;
//             root->right->right=rightTemp;

//             return root;
//         }
//         root->left=add(root->left,val,depth,curr+1);
//         root->right=add(root->right,val,depth,curr+1);

//         return root;
//     }
//     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
//         if(depth==1){
//             TreeNode* newRoot=new TreeNode(val);
//             newRoot->left=root;
//             return newRoot;
//         }
//         int curr=1;
//         return add(root,val,depth,curr);
//     }
// };
class Solution {
public:

    void addNode(TreeNode *root, int val, int depth, int curDep) {
        if (root == NULL) {
            return ;
        }

        if (curDep + 1 == depth) {
            TreeNode *ltemp = root->left;
            TreeNode *rtemp = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            if (ltemp) {
                root->left->left = ltemp;
            }

            if (rtemp) {
                root->right->right = rtemp;
            }
            return;
        }

        addNode(root->left, val, depth, curDep+1);
        addNode(root->right, val, depth, curDep+1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == NULL) {
            if (depth == 1) {
                return new TreeNode(val);
            }

            return NULL;
        }

        if (depth == 1) {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int curDepth = 1;
        addNode(root, val, depth, curDepth);
        return root;
    }
};