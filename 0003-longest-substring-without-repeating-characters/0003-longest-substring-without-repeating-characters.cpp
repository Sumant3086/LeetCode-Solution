class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        vector<int>freq(256,0);
        int maxL=0;
        int left=0;
        int right=0;
        while(right<n){
            freq[s[right]]++;
            while(freq[s[right]]>1){
                freq[s[left]]--;
                left++;
            }
            maxL=max(right-left+1,maxL);
            right++;
        }
        return maxL;
    }
};