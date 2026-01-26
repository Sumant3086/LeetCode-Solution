class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totS=0; 
        for(int n:nums){
            int sum=0;
            int cnt=0;
            for(int i=1;i*i<=n;++i){
                if(n%i==0){ 
                    cnt++;
                    sum+=i; 
                    if(i!=n/i){
                        cnt++;
                        sum+=n/i;
                    }
                }
                if(cnt>4)break; 
            }
            if(cnt==4){
                totS+=sum;
            }
        }
        return totS;
    }
};