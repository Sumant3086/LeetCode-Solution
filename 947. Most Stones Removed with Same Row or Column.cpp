// 947. Most Stones Removed with Same Row or Column
// Medium
// Topics
// Companies
// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

// Example 1:

// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Explanation: One way to remove 5 stones is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,1].
// 2. Remove stone [2,1] because it shares the same column as [0,1].
// 3. Remove stone [1,2] because it shares the same row as [1,0].
// 4. Remove stone [1,0] because it shares the same column as [0,0].
// 5. Remove stone [0,1] because it shares the same row as [0,0].
// Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
// Example 2:

// Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// Output: 3
// Explanation: One way to make 3 moves is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,0].
// 2. Remove stone [2,0] because it shares the same column as [0,0].
// 3. Remove stone [0,2] because it shares the same row as [0,0].
// Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
// Example 3:

// Input: stones = [[0,0]]
// Output: 0
// Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 

// Constraints:

// 1 <= stones.length <= 1000
// 0 <= xi, yi <= 104
// No two stones are at the same coordinate point.

class Disjoint {
public:
    vector<int> size, parent;
    Disjoint(int n) {
        for(int i = 0; i <= n; ++i) {
            size.push_back(1);
            parent.push_back(i);
        }
    }

    int findPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionn(int a, int b) {
        a = findPar(a);
        b = findPar(b);

        if(a == b) return;
        if(size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        } else {
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0, maxCol = 0;
        for(int i = 0; i < n; ++i) {
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        Disjoint *dsu = new Disjoint(maxRow + maxCol + 1);

        for(int i = 0; i < n; ++i) {
            int col = stones[i][1];
            int row = stones[i][0] + maxCol + 1;
            dsu -> unionn(row, col);
        } 
        set<int> numComp;
        for(int i = 0; i < n; ++i) {
            int row = stones[i][0] + maxCol + 1;
            int col = stones[i][1];
            numComp.insert(dsu -> findPar(row));
            numComp.insert(dsu -> findPar(col));
        }

        return n - (int)numComp.size();

    }
};