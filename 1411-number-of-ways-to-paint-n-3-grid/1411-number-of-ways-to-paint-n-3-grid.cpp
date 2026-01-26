class Solution {
public:
    int numOfWays(int n) {
        if(n==1)return 12;
        if(n==2)return 54;
        long long prv=54;
        long long prv2=12;
        long long mod=1e9+7;
        for(int i=3;i<=n;i++){
            long long curr=(5*prv-2*prv2)%mod;
            if(curr<0)curr+=mod;
            prv2=prv;
            prv=curr;
        }
        return prv;
    }
};