// 264. Ugly Number II
// Solved
// Medium
// Topics
// Companies
// Hint
// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return the nth ugly number.

 

// Example 1:

// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
// Example 2:

// Input: n = 1
// Output: 1
// Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

// Constraints:

// 1 <= n <= 1690
// Seen this question in a real interview before?
// 1/5
// Yes
// No

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long>uglyNS;
        uglyNS.insert(1);
        long currUgly=1;
        for(int i=0;i<n;i++){
            currUgly=*uglyNS.begin();
            uglyNS.erase(uglyNS.begin());
            uglyNS.insert(currUgly*2);
            uglyNS.insert(currUgly*3);
            uglyNS.insert(currUgly*5);
        }
        return static_cast<int>(currUgly);
    }
};