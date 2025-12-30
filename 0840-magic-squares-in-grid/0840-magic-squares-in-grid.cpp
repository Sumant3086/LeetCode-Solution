class Solution {
public:
    bool isMagic(vector<vector<int>>& grid,int startRow,int startCol){
        //Check whether the elements are disctinct or not
        unordered_map<int,int> mp;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int curr = grid[startRow+i][startCol+j];
                if(1>curr || curr>9 || mp.find(curr)!=mp.end()){
                    return false;
                }else{
                    mp[curr] = 1;
                }
            }
        }
        //sum of first row
        int sum = 0;
        for(int j=0;j<3;j++){
            sum+=grid[startRow][startCol+j];
        }
        //sum rows
        for(int i=0;i<3;i++){
            int rowSum = 0;
            for(int j=0;j<3;j++){
                rowSum+=grid[startRow+i][startCol+j];
            }
            if(rowSum!=sum){
                return false;
            }
        }
        //sum col
        for(int i=0;i<3;i++){
            int colSum = 0;
            for(int j=0;j<3;j++){
                colSum+=grid[startRow+j][startCol+i];
            }
            if(colSum!=sum){
                return false;
            }
        }
        //main diagonal
        int diagSum1 = 0;
        for(int i=0;i<3;i++){
            diagSum1+=grid[startRow+i][startCol+i];
        }
        if(diagSum1!=sum) return false;
        //anti diagonal
        int diagSum2 = 0;
        for(int i=0;i<3;i++){
            diagSum2+=grid[startRow+i][startCol+3-i-1];
        }
        if(diagSum2!=sum) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m < 3 || n < 3) return 0;
        int ans = 0;
        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                if(isMagic(grid,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};