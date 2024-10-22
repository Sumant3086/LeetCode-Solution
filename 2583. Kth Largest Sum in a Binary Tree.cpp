// 2583. Kth Largest Sum in a Binary Tree
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given the root of a binary tree and a positive integer k.

// The level sum in the tree is the sum of the values of the nodes that are on the same level.

// Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

// Note that two nodes are on the same level if they have the same distance from the root.

 

// Example 1:


// Input: root = [5,8,9,2,1,3,7,4,6], k = 2
// Output: 13
// Explanation: The level sums are the following:
// - Level 1: 5.
// - Level 2: 8 + 9 = 17.
// - Level 3: 2 + 1 + 3 + 7 = 13.
// - Level 4: 4 + 6 = 10.
// The 2nd largest level sum is 13.
// Example 2:


// Input: root = [1,2,null,3], k = 1
// Output: 3
// Explanation: The largest level sum is 3.
 

// Constraints:

// The number of nodes in the tree is n.
// 2 <= n <= 105
// 1 <= Node.val <= 106
// 1 <= k <= n

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 66.2K
// Submissions
// 124.7K
// Acceptance Rate
// 53.1%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (71)

// Choose a type



// Copyright ©️ 2024 LeetCode All rights reserved

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)return-1;
        priority_queue<long>pq;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long n=q.size();
            long long sum=0;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;
            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
        pq.push(sum);
    }
    if(pq.size()<k)return -1;
    for(int i=0;i<k-1;i++)pq.pop();
    return pq.top();
    }
};