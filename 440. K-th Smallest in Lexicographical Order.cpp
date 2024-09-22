// 440. K-th Smallest in Lexicographical Order
// Solved
// Hard
// Topics
// Companies
// Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

// Example 1:

// Input: n = 13, k = 2
// Output: 10
// Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
// Example 2:

// Input: n = 1, k = 1
// Output: 1
 

// Constraints:

// 1 <= k <= n <= 109


class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k>0){
            long long step=countSteps(n,curr,curr+1);
            if(step<=k){
                curr++;
                k-=step;
            }else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
private:
    long long countSteps(int n, long long curr, long long next) {
        long long steps=0;
        while(curr<=n){
            steps+=min((long long)n+1,next)-curr;
            curr*=10;
            next*=10;
        }
        return steps;
    }
};
