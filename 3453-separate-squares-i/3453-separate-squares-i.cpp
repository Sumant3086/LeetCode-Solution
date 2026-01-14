class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double tot=0;
        for(auto &s:squares){
            tot+=1.0*s[2]*s[2];
        }
        double needed=tot/2.0;
        double left=0,right=1e9;
        for(int i=0;i<80;i++){
            double mid=(left+right)/2;
            double curr=0;
            for(auto &s:squares){
                double b=s[1],t=b+s[2];
                curr+=max(0.0,min(mid,t)-b)*s[2];
            }
            (curr<needed?left:right)=mid;
        }
        return left;
    }
};