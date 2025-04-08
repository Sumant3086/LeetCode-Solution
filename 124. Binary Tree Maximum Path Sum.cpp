// 124. Binary Tree Maximum Path Sum
// Solved
// Hard
// Topics
// Companies
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

// Example 1:


// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
// Example 2:


// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 3 * 104].
// -1000 <= Node.val <= 1000
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 1.5M
// Submissions
// 3.7M
// Acceptance Rate
// 41.0%
// Topics
// Companies
// Similar Questions
// Discussion (237)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved
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
    int findMaxSum(TreeNode* root,int &maxSum){
            if(!root)return 0;
            int nodeMax=root->val;
            int leftM=findMaxSum(root->left,maxSum);
            int rightM=findMaxSum(root->right,maxSum);
            if(leftM>0)nodeMax+=leftM;
            if(rightM>0)nodeMax+=rightM;
            maxSum=max(maxSum,nodeMax);
            return max(root->val,root->val+max(leftM,rightM));
        }
        int maxPathSum(TreeNode* root) {
             int maxSum=INT_MIN;
            findMaxSum(root,maxSum);
            return maxSum;
        }
        
    };
