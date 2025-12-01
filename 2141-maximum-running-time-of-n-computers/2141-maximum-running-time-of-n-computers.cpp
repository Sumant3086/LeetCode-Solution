class Solution {
public:
    bool isP(long long t,int n,vector<int>& batteries){
        long long need=1LL*n*t;
        long long curr=0;
        for(long long i:batteries){
            curr+=min(i,t);
        }
        return curr>=need;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=0;
        for(int i:batteries)sum+=i;
        long long l=0;
        long long r=sum/n;
        while(l<r){
            long long mid=(l+r+1)/2;
            if(isP(mid,n,batteries)){
                l=mid;
            }else{
                r=mid-1;
            } 
        }
        return l;
    }
};