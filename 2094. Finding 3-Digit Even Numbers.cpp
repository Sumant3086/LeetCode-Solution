// 2094. Finding 3-Digit Even Numbers
// Solved
// Easy
// Topics
// Companies
// Hint
// You are given an integer array digits, where each element is a digit. The array may contain duplicates.

// You need to find all the unique integers that follow the given requirements:

// The integer consists of the concatenation of three elements from digits in any arbitrary order.
// The integer does not have leading zeros.
// The integer is even.
// For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

// Return a sorted array of the unique integers.

 

// Example 1:

// Input: digits = [2,1,3,0]
// Output: [102,120,130,132,210,230,302,310,312,320]
// Explanation: All the possible integers that follow the requirements are in the output array. 
// Notice that there are no odd integers or integers with leading zeros.
// Example 2:

// Input: digits = [2,2,8,8,2]
// Output: [222,228,282,288,822,828,882]
// Explanation: The same digit can be used as many times as it appears in digits. 
// In this example, the digit 8 is used twice each time in 288, 828, and 882. 
// Example 3:

// Input: digits = [3,7,5]
// Output: []
// Explanation: No even integers can be formed using the given digits.
 

// Constraints:

// 3 <= digits.length <= 100
// 0 <= digits[i] <= 9

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 71.8K
// Submissions
// 100K
// Acceptance Rate
// 71.9%
// Topics
// Companies
// Hint 1
// Similar Questions
// Discussion (73)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            vector<int> mpp(10, 0);
            for (int i = 0; i < digits.size(); i++)
                mpp[digits[i]]++;
    
            vector<int> res;
            for (int i = 1; i <= 9; i++) {
                if (mpp[i] == 0) continue;
                mpp[i]--;
    
                for (int j = 0; j <= 9; j++) {
                    if (mpp[j] == 0) continue;
                    mpp[j]--;
                    for (int k = 0; k <= 8; k += 2) {
                        if (mpp[k] == 0) continue;
                        mpp[k]--;
                        res.push_back(i*100 + j*10 + k);
                        mpp[k]++;
                    }
                    mpp[j]++;
    
                }
                mpp[i]++;
            }
            return res;
        }
    };