class Solution {
public:
    void fillOne(int i,int j,int n,int m,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1')return;
        grid[i][j]=0;
        fillOne(i+1,j,n,m,grid);
        fillOne(i,j+1,n,m,grid);
        fillOne(i-1,j,n,m,grid);
        fillOne(i,j-1,n,m,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                }
                fillOne(i,j,n,m,grid);
            }
        }
        return count;
    }
};