// 959. Regions Cut By Slashes
// Solved
// Medium
// Topics
// Companies
// An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

// Given the grid grid represented as a string array, return the number of regions.

// Note that backslash characters are escaped, so a '\' is represented as '\\'.

 

// Example 1:


// Input: grid = [" /","/ "]
// Output: 2
// Example 2:


// Input: grid = [" /","  "]
// Output: 1
// Example 3:


// Input: grid = ["/\\","\\/"]
// Output: 5
// Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
 

// Constraints:

// n == grid.length == grid[i].length
// 1 <= n <= 30
// grid[i][j] is either '/', '\', or ' '.

const int N = 31;

class UnionFind {
public:
    vector<int> par;
    vector<int> sz;
    UnionFind() {
        par.resize(N * N);
        sz.resize(N * N);
        for (int i = 0; i < N * N; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int u) {
        if (u == par[u])
            return u;
        return par[u] = find(par[u]);
    }

    void uni(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (sz[pu] >= sz[pv]) {
            sz[pu] += sz[pv];
            par[pv] = pu;
        } else {
            sz[pv] += sz[pu];
            par[pu] = pv;
        }
    }

    bool connected(int u, int v) { return find(u) == find(v); }
};

class Solution {
public:
    int getPoint(int i, int j) { return N * i + j; }

    int regionsBySlashes(vector<string>& grid) {
        UnionFind uf;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            int u = getPoint(0, i), v = getPoint(0, i + 1);
            uf.uni(u, v);
            u = getPoint(n, i), v = getPoint(n, i + 1);
            uf.uni(u, v);
        }
        for (int i = 0; i < n; i++) {
            int u = getPoint(i, 0), v = getPoint(i + 1, 0);
            uf.uni(u, v);
            u = getPoint(i, n), v = getPoint(i + 1, n);
            uf.uni(u, v);
        }
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int u, v;
                if (grid[i][j] == '/') {
                    u = getPoint(i, j + 1);
                    v = getPoint(i + 1, j);
                } else if (grid[i][j] == '\\') {
                    u = getPoint(i, j);
                    v = getPoint(i + 1, j + 1);
                } else
                    continue;
                if (uf.connected(u, v))
                    ans++;
                uf.uni(u, v);
            }
        }
        return ans;
    }
};