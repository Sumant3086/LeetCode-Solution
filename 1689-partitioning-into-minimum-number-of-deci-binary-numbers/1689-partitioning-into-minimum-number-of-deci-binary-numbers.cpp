class Solution {
public:
    int minPartitions(string n) {
        int maxD=0;
        for(char c:n){
            maxD=max(maxD,c-'0');
        }
        return maxD;
    }
};