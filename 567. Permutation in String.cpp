// 567. Permutation in String
// Solved
// Medium
// Topics
// Companies
// Hint
// Given two strings s1 and s2, return true if s2 contains a 
// permutation
//  of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 965K
// Submissions
// 2.1M
// Acceptance Rate
// 45.2%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Hint 4
// Hint 5
// Hint 6
// Similar Questions
// Discussion (165)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n>m)return false;
        unordered_map<int,int>mp;
        for(auto ch:s1){
            mp[ch-'a']++;
        }
        int i=0,j=0,count=0;
        while(j<m){
            if(mp[s2[j]-'a']>0){
                count++;
                mp[s2[j]-'a']--;
                j++;
            }else{
                if(count==n)return true;
                if(mp.find(s2[i]-'a')!=mp.end()){
                    mp[s2[i]-'a']++;
                    count--;
                }
                i++;
            }
        }
        if(count==n)return true;
        return false;
    }
};
 static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();