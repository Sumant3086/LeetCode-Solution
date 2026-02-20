class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.size()<=2)return s;
        vector<string>v;
        int cnt=0;
        int start=0;
        for(int i=0;i<s.size();i++){
            cnt+=(s[i]=='1')?1:-1;
            if(cnt==0){
                v.push_back("1"+ makeLargestSpecial(s.substr(start+1, i-start-1))+"0");
                start=i+1;
            }
        }
        sort(v.rbegin(),v.rend());
        string ans;
        for(auto &str:v){
            ans+=str;
        }
        return ans; 
    }
};