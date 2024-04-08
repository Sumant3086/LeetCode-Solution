// 204. Count Primes
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an integer n, return the number of prime numbers that are strictly less than n.

 

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0
 

// Constraints:

// 0 <= n <= 5 * 106

// class Solution {
// public:
//     int countPrimes(int n) {
//         int count=0;
//         vector<bool>prime(n+1,true);
//         prime[0]=prime[1]=false;
//         for(int i=2;i<n;i++){
//             if(prime[i]){
//             count++;
//             for(int j=2*i;j<n;j=j+i){
//             prime[j]=0;
//             }
//         }
//     }
//         return count;
//     }
// };

class Solution {
public:
    int countPrimes(int n) {
        bitset<10000000>bt;
        for(int i=2;i<n;i++){
            bt.set(i);
        }

        for(int i =2;i<n;i++){
            if(bt[i]){
                for(int j=2;j*i<n;j++){
                    bt.reset(i*j);
                }
            }
        }

        return bt.count();

    }
};