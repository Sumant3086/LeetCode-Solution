class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int mod=1e9+7;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,0)));
        dp[0][0][grid[0][0]%k]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int r=0;r<k;r++){
                    int ways=dp[i][j][r];
                    if(!ways)continue;
                    if(i+1<m){
                        int newR=(r+grid[i+1][j])%k;
                        dp[i+1][j][newR]=(dp[i+1][j][newR]+ways)%mod;
                    }
                    if(j+1<n){
                        int newR=(r+grid[i][j+1])%k;
                        dp[i][j+1][newR]=(dp[i][j+1][newR]+ways)%mod;
                    }
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};