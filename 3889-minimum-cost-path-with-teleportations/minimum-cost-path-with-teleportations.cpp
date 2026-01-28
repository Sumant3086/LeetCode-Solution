class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size(); 
        vector<vector<int>>dp(m,vector<int>(n,1e9));
        dp[0][0]=0;
        int ans=1e9; 
        for(int t=0;t<=k;++t){ 
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    if(dp[i][j]>=1e9)continue; 
                    if(i+1<m){
                        dp[i+1][j]=min(dp[i+1][j],dp[i][j]+grid[i+1][j]);
                    }
                    if(j+1<n){
                        dp[i][j+1]=min(dp[i][j+1],dp[i][j]+grid[i][j+1]);
                    }
                }
            } 
            ans=min(ans,dp[m-1][n-1]);
            if(t==k)break; 
            vector<int>minV(10002,1e9);
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    if(dp[i][j]<1e9) 
                        minV[grid[i][j]]=min(minV[grid[i][j]],dp[i][j]);
                }
            } 
            for(int v=10000;v>=0;--v){
                minV[v]=min(minV[v],minV[v+1]);
            } 
            vector<vector<int>> nxtdp(m,vector<int>(n, 1e9));
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){ 
                    nxtdp[i][j]=minV[grid[i][j]];
                }
            }
            dp=nxtdp;
        }        
        return ans;
    }
};