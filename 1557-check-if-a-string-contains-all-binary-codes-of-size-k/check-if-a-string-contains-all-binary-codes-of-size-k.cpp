class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        if(n<k)return false;
        int total=1<<k; 
        unordered_set<int>seen;
        int hash=0;
        int mask=total-1;
        for(int i=0;i<n;i++){
            hash=((hash<<1)&mask)|(s[i]-'0'); 
            if(i>=k-1){
                seen.insert(hash);
                if(seen.size()==total)
                    return true;
            }
        } 
        return false;
    }
};