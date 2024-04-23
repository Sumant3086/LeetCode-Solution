// 310. Minimum Height Trees
// Solved
// Medium
// Topics
// Companies
// Hint
// A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

// Return a list of all MHTs' root labels. You can return the answer in any order.

// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

// Example 1:


// Input: n = 4, edges = [[1,0],[1,2],[1,3]]
// Output: [1]
// Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
// Example 2:


// Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
// Output: [3,4]
 

// Constraints:

// 1 <= n <= 2 * 104
// edges.length == n - 1
// 0 <= ai, bi < n
// ai != bi
// All the pairs (ai, bi) are distinct.
// The given input is guaranteed to be a tree and there will be no repeated edges.

// class Solution {
// public:
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//          ios::sync_with_stdio(0);
//             cin.tie(0); cout.tie(0);
//         unordered_map<int, vector<int>>adj;
//         vector<int>inDeg(n);
//         if(n==1){
//             return {0};                                                                                                                                       
//         }
//         for(auto &edge:edges){
//             int u=edge[0];
//             int v=edge[1];
//             inDeg[u]++;
//             inDeg[v]++;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         vector<int>result;
//         queue<int>que;
//         for(int i=0;i<n;i++){
//             if(inDeg[i]==1){
//                 que.push(i);
//             }
//         }
//         while(n>2){
//             int size=que.size();
//             n-=size;
//             while(size--){
//                 int u=que.front();
//                 que.pop();
//                 for(int &v:adj[u]){
//                     --inDeg[v];
//                     if(inDeg[v]==1){
//                         que.push(v);
//                     }
//                 }
//             }
//         }
//         while(!que.empty()){
//             result.push_back(que.front());
//             que.pop();
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<pair<int,int>> connectInfo(n);
        // Info - first : acc of vertex
        //      - second: connect number

        for(auto& edge : edges)
        {
            connectInfo[edge[0]].first += edge[1];
            connectInfo[edge[0]].second++;
            connectInfo[edge[1]].first += edge[0];
            connectInfo[edge[1]].second++;
        }

        vector<int> NotRootVertex;
        for(int i = 0 ; i < n ; i++)
        {
            if(connectInfo[i].second == 1)
                NotRootVertex.push_back(i);
        }
        
        vector<int> newLeave;
        while(n > 2)
        {
            n -= NotRootVertex.size();
            newLeave.clear();
            for(int i = 0 ; i < NotRootVertex.size() ; i++)
            {
                connectInfo[connectInfo[NotRootVertex[i]].first].first -= NotRootVertex[i];
                connectInfo[connectInfo[NotRootVertex[i]].first].second--;

                if(connectInfo[connectInfo[NotRootVertex[i]].first].second == 1)
                    newLeave.push_back(connectInfo[NotRootVertex[i]].first);
            }
            
            NotRootVertex = newLeave;
        }

        return NotRootVertex;
    }
};