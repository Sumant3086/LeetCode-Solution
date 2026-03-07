class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        string tot=s+s;
        int res=n,diff1=0,diff2=0;
        for(int i=0;i<2*n;i++){
            if(tot[i]!=(i%2?'1':'0'))diff1++;
            if(tot[i]!=(i%2?'0':'1'))diff2++;
            if(i>=n){
                if(tot[i-n]!=((i-n)%2?'1':'0'))diff1--;
                if(tot[i-n]!=((i-n)%2?'0':'1'))diff2--;
            }
            if(i>=n-1){
                res=min(res,min(diff1,diff2));
            }
        }    
        return res;
    }
};