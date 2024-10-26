// 2458. Height of Binary Tree After Subtree Removal Queries
// Solved
// Hard
// Topics
// Companies
// Hint
// You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.

// You have to perform m independent queries on the tree where in the ith query you do the following:

// Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
// Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.

// Note:

// The queries are independent, so the tree returns to its initial state after each query.
// The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.
 

// Example 1:


// Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
// Output: [2]
// Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
// The height of the tree is 2 (The path 1 -> 3 -> 2).
// Example 2:


// Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
// Output: [3,2,3,2]
// Explanation: We have the following queries:
// - Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 4).
// - Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -> 8 -> 1).
// - Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
// - Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -> 9 -> 3).
 

// Constraints:

// The number of nodes in the tree is n.
// 2 <= n <= 105
// 1 <= Node.val <= n
// All the values in the tree are unique.
// m == queries.length
// 1 <= m <= min(n, 104)
// 1 <= queries[i] <= n
// queries[i] != root.val

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 38.9K
// Submissions
// 86.2K
// Acceptance Rate
// 45.2%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (53)

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
    map<int, int> nodeToLevel;
    map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> levelToHeight;

    int fillMap(TreeNode* root, int level = 0) {
        if (!root) return 0;

        nodeToLevel[root->val] = level;

        int lh = fillMap(root->left, level + 1);
        int rh = fillMap(root->right, level + 1);
        
        int height = max(lh, rh);

        levelToHeight[level].push({height, root->val});
        if (levelToHeight[level].size() > 2) {
            levelToHeight[level].pop();
        }

        return 1+height;
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        nodeToLevel.clear();
        levelToHeight.clear();
        int h = fillMap(root)-1;

        vector<int> ans;
        for (auto q : queries) {
            int level = nodeToLevel[q];

            auto pq = levelToHeight[level];
            auto top2 = pq.top(); pq.pop();
            auto top1 = pq.empty() ? make_pair(0, -1) :pq.top(); pq.push(top2);

            if (q == top1.second) {
                ans.push_back(h - top1.first + top2.first);
            }
            else if(pq.size()==1 && q == top2.second){
                ans.push_back(h - top2.first - 1);
            }
            else {
                ans.push_back(h);
            }
        }

        return ans;
    }
};
auto speedup = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();