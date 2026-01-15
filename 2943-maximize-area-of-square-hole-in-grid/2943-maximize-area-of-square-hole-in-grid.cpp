class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto getG=[](vector<int>& v){
            sort(v.begin(),v.end());
            int maxL=1,curr=1;
            for(int i=1;i<v.size();i++){
                maxL=max(maxL,curr=(v[i]==v[i-1]+1)?curr+1:1);
            }
            return maxL+1;
        };
        int side=min(getG(hBars),getG(vBars));
        return side*side;
    }
};