class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        long long count=0;
        for(int i=0;i<prices.size();i++){
            if(i>0 && prices[i-1]-prices[i]==1){
                count++;
            }else{
                count=1;
            }
            ans+=count;
        }
        return ans;
    }
};