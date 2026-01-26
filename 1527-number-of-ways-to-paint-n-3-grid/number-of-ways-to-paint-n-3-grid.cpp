class Solution {
public:
    int numOfWays(int n) {
        long long mod=1e9+7;
        long long abc=6;
        long long aba=6;
        for(int i=2;i<=n;i++){
            long long prv1=(2*abc+2*aba)%mod;
            long long prv=(2*abc+3*aba)%mod;
            abc=prv1;
            aba=prv;
        }
        return (int)((abc+aba)%mod);
    }
};
// class Solution {
// public:
//     int numOfWays(int n) {
//         if(n==1)return 12;
//         if(n==2)return 54;
//         long long prv=54;
//         long long prv2=12;
//         long long mod=1e9+7;
//         for(int i=3;i<=n;i++){
//             long long curr=(5*prv-2*prv2)%mod;
//             if(curr<0)curr+=mod;
//             prv2=prv;
//             prv=curr;
//         }
//         return prv;
//     }
// };