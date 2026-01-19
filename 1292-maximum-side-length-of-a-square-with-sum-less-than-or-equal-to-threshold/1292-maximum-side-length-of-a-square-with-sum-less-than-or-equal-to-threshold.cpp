class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>sum(m+1,vector<int>(n+1,0));
        int curr=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                sum[i][j]=mat[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
                int currL=curr+1;
                if(i>=currL && j>=currL){
                    int currS=sum[i][j]-sum[i-currL][j]-sum[i][j-currL]+sum[i-currL][j-currL];
                    if(currS<=threshold){
                        curr++;
                    }
                }
            }
        }
        return curr;
    }
};