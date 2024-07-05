513. Find Bottom Left Tree Value
Solved
Medium
Topics
Companies
Given the root of a binary tree, return the leftmost value in the last row of the tree.

 

Example 1:


Input: root = [2,1,3]
Output: 1
Example 2:


Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
 

// class Solution {
// public:
//     int findBottomLeftValue(TreeNode* root) {
//         queue<TreeNode*> levelQue;
//         levelQue.push(root);
//         int leftNodeVal=root->val;
//         while(!levelQue.empty()){
//             int currLevelSize=levelQue.size();
//             int orgSize=currLevelSize;
//             while(currLevelSize-->0){
//                 TreeNode* currNode=levelQue.front();
//                 levelQue.pop();
//                 if(orgSize-1==currLevelSize)
//                     leftNodeVal=currNode->val;
//                 if(currNode->left!=NULL)levelQue.push(currNode->left);
//                 if(currNode->right!=NULL)levelQue.push(currNode->right);
//             }
//         }   
//         return leftNodeVal;
//     }
// };

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
    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr) return -1;
        queue<TreeNode*> q;
        q.push(root);
        int bottomLeftValue = root->val;

        while(!q.empty()){
            int n = q.size();

            for(int i = 0; i < n; i++){
               TreeNode* temp = q.front();
               q.pop();

               if(i == 0){
                    bottomLeftValue = temp->val;
                }

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

            }

        }
        return bottomLeftValue;
        
    }
};