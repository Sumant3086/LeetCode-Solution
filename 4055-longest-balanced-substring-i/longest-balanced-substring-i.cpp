class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int res=1;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            int diff=0;
            int maxF=0;
            for(int j=i;j<n;j++){
                int ch=s[j]-'a';
                if(freq[ch]==0)diff++;
                freq[ch]++;
                maxF=max(maxF,freq[ch]);
                if((j-i+1)==diff*maxF){
                    res=max(res,j-i+1);
                }
            }
        }
        return res;
    }
};