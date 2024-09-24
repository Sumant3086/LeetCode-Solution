// 2514. Count Anagrams
// Solved
// Hard
// Topics
// Companies
// Hint
// You are given a string s containing one or more words. Every consecutive pair of words is separated by a single space ' '.

// A string t is an anagram of string s if the ith word of t is a permutation of the ith word of s.

// For example, "acb dfe" is an anagram of "abc def", but "def cab" and "adc bef" are not.
// Return the number of distinct anagrams of s. Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: s = "too hot"
// Output: 18
// Explanation: Some of the anagrams of the given string are "too hot", "oot hot", "oto toh", "too toh", and "too oht".
// Example 2:

// Input: s = "aa"
// Output: 1
// Explanation: There is only one anagram possible for the given string.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters and spaces ' '.
// There is single space between consecutive words.

// Seen this question in a real interview before?
// 1/5

static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    const int MOD=1e9+7;
    long long factorial(int n){
        long long result=1;
        for(int i=2;i<=n;++i){
            result=(result*i)%MOD;
        }
        return result;
    }
    long long modInverse(long long x,long long mod){
        long long res=1;
        long long power=mod-2; 
        while(power>0){
            if(power%2==1){
                res=(res*x)%mod;
            }
            x=(x*x)%mod;
            power/=2;
        }
        return res;
    }
    int countAnagrams(string s){
        long long result=1;
        string word;
        stringstream ss(s);

        while(ss>>word){
            unordered_map<char, int> freq;
            for(char c:word){
                freq[c]++;
            }
            long long wordAnagrams=factorial(word.length());
            for(auto& [ch,count]:freq){
                wordAnagrams=(wordAnagrams*modInverse(factorial(count),MOD))%MOD;
            }
            result=(result*wordAnagrams)%MOD;
        }
        return result;
    }
};
