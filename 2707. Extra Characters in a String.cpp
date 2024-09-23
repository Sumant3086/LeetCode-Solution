// 2707. Extra Characters in a String
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

// Return the minimum number of extra characters left over if you break up s optimally.

 

// Example 1:

// Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
// Output: 1
// Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

// Example 2:

// Input: s = "sayhelloworld", dictionary = ["hello","world"]
// Output: 3
// Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
 

// Constraints:

// 1 <= s.length <= 50
// 1 <= dictionary.length <= 50
// 1 <= dictionary[i].length <= 50
// dictionary[i] and s consists of only lowercase English letters
// dictionary contains distinct words



static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const int n=s.length();
        const unordered_set<string>dicSet{dictionary.begin(),dictionary.end()};
        vector<int>dp(n+1,n);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dicSet.contains(s.substr(j,i-j))){
                    dp[i]=min(dp[i],dp[j]);
                }else{
                    dp[i]=min(dp[i],dp[j]+i-j);
                }
            }
        }
        return dp[n];
    }
};