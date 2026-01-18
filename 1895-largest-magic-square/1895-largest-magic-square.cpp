class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); 
        for(int k=min(m,n);k>1;--k){
            for(int i=0;i<=m-k;++i){
                for(int j=0;j<=n-k;++j){ 
                    long target=0,anti=0;
                    for(int d=0;d<k;++d){
                        target+=grid[i+d][j+d];
                        anti+=grid[i+d][j+k-1-d];
                    }
                    if(target!=anti) continue; 
                    bool valid=true;
                    for(int r=0;r<k;++r){
                        long rowSum=0,colSum=0;
                        for(int c=0;c<k;++c){
                            rowSum+=grid[i+r][j+c];
                            colSum+=grid[i+c][j+r];
                        }
                        if(rowSum!=target || colSum!=target){
                            valid=false;
                            break;
                        }
                    }
                    if(valid)return k;
                }
            }
        }
        return 1;
    }
};