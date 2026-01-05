class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int neg=0,mn=INT_MAX;
        for(auto &r:matrix)
            for(int x:r){
                if(x<0)neg++;
                sum+=llabs(x);
                mn=min(mn,abs(x));
            }
        return (neg%2==0)?sum:sum-2LL*mn;
    }
};
