// 402. Remove K Digits
// Solved
// Medium
// Topics
// Companies
// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

// Constraints:

// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 423.5K
// Submissions
// 1.3M
// Acceptance Rate
// 32.4%
// Topics
// Companies
// Similar Questions
// Discussion (152)

class Solution {
public:
    string removeKdigits(string num, int k) {
       string ans="";
        int n=num.length();
        for(int i=0;i<n;i++){
            while(ans.length()>0 && ans.back()>num[i] && k>0){
                ans.pop_back();
                k--;
            }
            if(ans.length()>0 || num[i]!='0'){
            ans.push_back(num[i]);  //to avoid preceeding zeroes
            }
        }
        while(ans.length()>0 && k>0){
            ans.pop_back();
            k--;
        }
        if(ans==""){
            return "0";
        }
        return ans;
    }
};