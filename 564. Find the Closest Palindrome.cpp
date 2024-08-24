// 564. Find the Closest Palindrome
// Solved
// Hard
// Topics
// Companies
// Hint
// Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.

// The closest is defined as the absolute difference minimized between two integers.

 

// Example 1:

// Input: n = "123"
// Output: "121"
// Example 2:

// Input: n = "1"
// Output: "0"
// Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
 

// Constraints:

// 1 <= n.length <= 18
// n consists of only digits.
// n does not have leading zeros.
// n is representing an integer in the range [1, 1018 - 1].


class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.length()==1)
            return to_string(stoi(n)-1);
        
        int d = n.length();
        vector<long> candidates;
        candidates.push_back(pow(10,d-1)-1);
        candidates.push_back(pow(10,d)+1);

        int mid = (d+1)/2;
        long prefix = stol(n.substr(0,mid));
        vector<long> v = {prefix,prefix+1, prefix-1};
        for(long i : v)
        {
            string postfix = to_string(i);
            if(d%2!=0)
                postfix.pop_back();
            reverse(postfix.begin(), postfix.end());
            string c = to_string(i)+postfix;
            candidates.push_back(stol(c));
        }
        long mindiff = LONG_MAX;
        long result;
        long num = stol(n);
        for(int i=0;i<5;i++)
        {
            if(candidates[i]!=num && abs(candidates[i]-num)<mindiff)
            {
                mindiff = abs(candidates[i]-num);
                result = candidates[i];
            }
            else if(abs(candidates[i]-num)==mindiff)
                result = min(result, candidates[i]);
        }
        return to_string(result);
    }
};