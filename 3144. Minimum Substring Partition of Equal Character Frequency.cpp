// 3144. Minimum Substring Partition of Equal Character Frequency
// Solved
// Medium
// Companies
// Hint
// Given a string s, you need to partition it into one or more balanced 
// substrings
// . For example, if s == "ababcc" then ("abab", "c", "c"), ("ab", "abc", "c"), and ("ababcc") are all valid partitions, but ("a", "bab", "cc"), ("aba", "bc", "c"), and ("ab", "abcc") are not. The unbalanced substrings are bolded.

// Return the minimum number of substrings that you can partition s into.

// Note: A balanced string is a string where each character in the string occurs the same number of times.

 

// Example 1:

// Input: s = "fabccddg"

// Output: 3

// Explanation:

// We can partition the string s into 3 substrings in one of the following ways: ("fab, "ccdd", "g"), or ("fabc", "cd", "dg").

// Example 2:

// Input: s = "abababaccddb"

// Output: 2

// Explanation:

// We can partition the string s into 2 substrings like so: ("abab", "abaccddb").

 

// Constraints:

// 1 <= s.length <= 1000
// s consists only of English lowercase letters.

class Solution {
public:
    bool isBalanced(vector<int> &charFreq){
        int minFreq=1001,maxFreq=0;
        for(int Freq:charFreq){
            if(Freq>0){
                minFreq=min(minFreq,Freq);
                maxFreq=max(maxFreq,Freq);
            }
        }
        return minFreq==maxFreq;
    }
    int minimumSubstringsInPartition(string S){
        int N=S.size();
        vector<int>DP(N,N);
        for(int END=0;END<N;END++){
            vector<int>charFreq(26,0);
            for(int START=END;START>=0;START--){
                charFreq[S[START]-'a']++;
                if(isBalanced(charFreq)){
                    DP[END]=START>0?min(DP[END],1+DP[START-1]):1;
                }
            }
        }
        return DP[N-1];
    }
};