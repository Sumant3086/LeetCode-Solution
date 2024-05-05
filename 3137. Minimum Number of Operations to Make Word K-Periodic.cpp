// 3137. Minimum Number of Operations to Make Word K-Periodic
// Attempted
// Medium
// Companies
// Hint
// You are given a string word of size n, and an integer k such that k divides n.

// In one operation, you can pick any two indices i and j, that are divisible by k, then replace the 
// substring
//  of length k starting at i with the substring of length k starting at j. That is, replace the substring word[i..i + k - 1] with the substring word[j..j + k - 1].

// Return the minimum number of operations required to make word k-periodic.

// We say that word is k-periodic if there is some string s of length k such that word can be obtained by concatenating s an arbitrary number of times. For example, if word == “ababab”, then word is 2-periodic for s = "ab".

 

// Example 1:

// Input: word = "leetcodeleet", k = 4

// Output: 1

// Explanation:

// We can obtain a 4-periodic string by picking i = 4 and j = 0. After this operation, word becomes equal to "leetleetleet".

// Example 2:

// Input: word = "leetcoleet", k = 2

// Output: 3

// Explanation:

// We can obtain a 2-periodic string by applying the operations in the table below.

// i	j	word
// 0	2	etetcoleet
// 4	0	etetetleet
// 6	0	etetetetet
 
 

// Constraints:

// 1 <= n == word.length <= 105
// 1 <= k <= word.length
// k divides word.length.
// word consists only of lowercase English letters.

const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
// class Solution {
// public:
//     int minimumOperationsToMakeKPeriodic(string s, int k) {
//         int n=s.size();
//         map<string,int> mp ;
//         int maxFreq=0;
//         int Tcount=0;
//         for(int i=0;i<n;i=i+k){
//             string t=s.substr(i,k);
//             mp[t]++;
//             maxFreq = max(maxFreq,mp[t]);
//             Tcount++;
//         } 
//         return Tcount - maxFreq;
//     }
// };

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        const int n=word.length();
        int m=0;
        unordered_map<string, int> have;
        for(int i=0;i<n;i+=k){
            m=max(m,++have[word.substr(i,k)]);
        }
        return n/k-m;
    }
};
