// 2471. Minimum Number of Operations to Sort a Binary Tree by Level
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given the root of a binary tree with unique values.

// In one operation, you can choose any two nodes at the same level and swap their values.

// Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.

// The level of a node is the number of edges along the path between it and the root node.

 

// Example 1:


// Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
// Output: 3
// Explanation:
// - Swap 4 and 3. The 2nd level becomes [3,4].
// - Swap 7 and 5. The 3rd level becomes [5,6,8,7].
// - Swap 8 and 7. The 3rd level becomes [5,6,7,8].
// We used 3 operations so return 3.
// It can be proven that 3 is the minimum number of operations needed.
// Example 2:


// Input: root = [1,3,2,7,6,5,4]
// Output: 3
// Explanation:
// - Swap 3 and 2. The 2nd level becomes [2,3].
// - Swap 7 and 4. The 3rd level becomes [4,6,5,7].
// - Swap 6 and 5. The 3rd level becomes [4,5,6,7].
// We used 3 operations so return 3.
// It can be proven that 3 is the minimum number of operations needed.
// Example 3:


// Input: root = [1,2,3,4,5,6]
// Output: 0
// Explanation: Each level is already sorted in increasing order so return 0.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 105
// All the values of the tree are unique.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 76.3K
// Submissions
// 104.9K
// Acceptance Rate
// 72.8%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Hint 4
// Similar Questions
// Discussion (87)

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int cnt = 0;

        auto minSwaps = [&](vector<int>& ans) -> int {
            if (ans.size() == 1)
                return 0;
            vector<int> temp = ans;
            sort(temp.begin(), temp.end());
            unordered_map<int, int> map;
            for (int i = 0; i < ans.size(); i++)
                map[ans[i]] = i;

            int cnt = 0;
            for (int i = 0; i < ans.size(); ++i) {
                if (ans[i] != temp[i]) {
                    int x = ans[i];
                    int idx = map[temp[i]];
                    ans[i] = temp[i];
                    ans[idx] = x;
                    map[ans[i]] = i;
                    map[x] = idx;
                    ++cnt;
                }
            }
            return cnt;
        };

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> ans;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                q.pop();
                ans.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            cnt += minSwaps(ans);
        }

        return cnt;
    }
};