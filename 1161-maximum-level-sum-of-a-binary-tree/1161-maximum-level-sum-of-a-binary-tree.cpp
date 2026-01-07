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
    vector<long long>levelSum;
    void dfs(TreeNode* root,int level){
        if(!root)return;
        if(level==levelSum.size()){
            levelSum.push_back(0);
        }
        levelSum[level]+=root->val;
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root,0);
        int best=INT_MIN;
        int level=0;
        int res=1;
        for(int i=0;i<levelSum.size();i++){
            if(levelSum[i]>best){
                best=levelSum[i];
                res=i+1;
            }
        }
        return res;
    }
};

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
// class Solution {
// public:
//     int maxLevelSum(TreeNode* root) {
//         queue<TreeNode*>q;
//         q.push(root);
//         int level=1;
//         int maxi=INT_MIN;
//         int res=1;
//         while(!q.empty()){
//             int n=q.size();
//             int sum=0;
//             while(n--){
//                 auto curr=q.front();
//                 q.pop();
//                 sum+=curr->val;
//                 if(curr->left)q.push(curr->left);
//                 if(curr->right)q.push(curr->right);
//             }
//             if(sum>maxi){
//                 maxi=sum;
//                 res=level;
//             }
//             level++;
//         }   
//     return res;
//     }
// };