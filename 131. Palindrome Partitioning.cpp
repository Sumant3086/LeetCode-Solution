// 131. Palindrome Partitioning
// Solved
// Medium
// Topics
// Companies
// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>path;
        backtrack(s,0,path,result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
         if(start==s.length()){
            result.push_back(path);
            return;
        } 
        for(int end=start+1;end<=s.length();++end){ 
            if(isPalindrome(s,start,end-1)){
                path.push_back(s.substr(start,end-start));
                backtrack(s,end,path,result); 
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) { 
        while(left<right){
            if(s[left++]!=s[right--]){
                return false;
            }
        }
        return true;
    }
};