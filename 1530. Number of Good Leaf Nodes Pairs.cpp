// 1530. Number of Good Leaf Nodes Pairs
// Solved
// Medium
// Topics
// Companies
// Hint

// You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

// Return the number of good leaf node pairs in the tree.

//  

// Example 1:

// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
// Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.


// Example 2:

// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.


// Example 3:

// Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
// Output: 1
// Explanation: The only good pair is [2,5].


//  

// Constraints:

// The number of nodes in the tree is in the range [1, 210].
// 1 <= Node.val <= 100
// 1 <= distance <= 10
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 142.4K
// Submissions
// 197.8K
// Acceptance Rate
// 72.0%
// Topics
// Tree
// Depth-First Search
// Binary Tree
// Companies
// Hint 1
// Start DFS from each leaf node. stop the DFS when the number of steps done > distance.
// Hint 2
// If you reach another leaf node within distance steps, add 1 to the answer.
// Hint 3
// Note that all pairs will be counted twice so divide the answer by 2.
// Discussion (185)
// Choose a type
// Preview
// Comment
// 💡 Discussion Rules

// 1. Please don't post any solutions in this discussion.

// 2. The problem discussion is for asking questions about the problem or for sharing tips - anything except for solutions.

// 3. If you'd like to share your solution for feedback and ideas, please head to the solutions tab and post it there.

// Sort by:Best
// No comments yet.
// 1
// 2
// 3
// 4
// 5
// 6
// 19
// Copyright ©️ 2024 LeetCode All rights reserved

#include <ranges>

static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

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
  static constexpr auto max_tracked_depth = 9;
  struct SearchStats {
    array<int, max_tracked_depth> depth_to_leaf_counts;
    int num_good_pairs;
  };
  static SearchStats dfs(TreeNode *root, int distance) {
    if (!root) return {{}, 0};
    if (!(root->left || root->right)) return {{1}, 0};
    auto left_stats = dfs(root->left, distance);
    auto right_stats = dfs(root->right, distance);

    auto num_new_good_pairs = 0;
    auto distance_window_count = accumulate(
        begin(right_stats.depth_to_leaf_counts),
        begin(right_stats.depth_to_leaf_counts) + distance - 1,
        0);
    for (auto i : views::iota(0, distance - 1)) {
      num_new_good_pairs += 
          left_stats.depth_to_leaf_counts[i] * distance_window_count;
      distance_window_count -= right_stats.depth_to_leaf_counts[distance - 2 - i];
    }

    auto merged_depth_to_leaf_counts = array<int, max_tracked_depth>{};
    for (auto i : views::iota(0, distance - 2))
      merged_depth_to_leaf_counts[i + 1] = left_stats.depth_to_leaf_counts[i]
          + right_stats.depth_to_leaf_counts[i];

    auto merged_num_good_pairs = num_new_good_pairs + left_stats.num_good_pairs + right_stats.num_good_pairs;

    return {merged_depth_to_leaf_counts, merged_num_good_pairs};

  }
public:
  int countPairs(TreeNode* root, int distance) {
    if (distance == 1) return 0;
    return dfs(root, distance).num_good_pairs;
  }
};