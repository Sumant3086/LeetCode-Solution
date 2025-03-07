// 2523. Closest Prime Numbers in Range
// Medium
// Topics
// Companies
// Hint
// Given two positive integers left and right, find the two integers num1 and num2 such that:

// left <= num1 < num2 <= right .
// Both num1 and num2 are prime numbers.
// num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
// Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 

// Example 1:

// Input: left = 10, right = 19
// Output: [11,13]
// Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
// The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
// Since 11 is smaller than 17, we return the first pair.
// Example 2:

// Input: left = 4, right = 6
// Output: [-1,-1]
// Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
 

// Constraints:

// 1 <= left <= right <= 106
 


// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 119.7K
// Submissions
// 240.8K
// Acceptance Rate
// 49.7%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (118)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
    public:
        vector<int> closestPrimes(int left, int right) { 
            vector<bool> isPrime(right + 1, true);
            isPrime[0] = isPrime[1] = false;
    
            for (int i = 2; i * i <= right; i++) {
                if (isPrime[i]) {
                    for (int j = i * i; j <= right; j += i)
                        isPrime[j] = false;
                }
            }
    
            int prev = -1, num1 = -1, num2 = -1, minGap = 1e6;
            for (int i = left; i <= right; i++) {
                if (isPrime[i]) {
                    if (prev != -1 && i - prev < minGap) {
                        minGap = i - prev;
                        num1 = prev, num2 = i;
                    }
                    prev = i;
                }
            }
            
            return (num1 == -1) ? vector<int>{-1, -1} : vector<int>{num1, num2};
        }
    };
    