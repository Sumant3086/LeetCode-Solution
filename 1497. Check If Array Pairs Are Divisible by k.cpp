// 1497. Check If Array Pairs Are Divisible by k
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array of integers arr of even length n and an integer k.

// We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

// Return true If you can find a way to do that or false otherwise.

 

// Example 1:

// Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
// Output: true
// Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
// Example 2:

// Input: arr = [1,2,3,4,5,6], k = 7
// Output: true
// Explanation: Pairs are (1,6),(2,5) and(3,4).
// Example 3:

// Input: arr = [1,2,3,4,5,6], k = 10
// Output: false
// Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
 

// Constraints:

// arr.length == n
// 1 <= n <= 105
// n is even.
// -109 <= arr[i] <= 109
// 1 <= k <= 105

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 103.1K
// Submissions
// 240.1K
// Acceptance Rate
// 42.9%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Similar Questions
// Discussion (92)

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>mp(k,0);
        for(int &nums:arr){
            int rem=(nums%k + k)%k;//handing (-)ve rem
            mp[rem]++;
        }
        if(mp[0]%2!=0){
            return false;
        }
        for(int rem=1;rem<=k/2;rem++){
            int half=k-rem;
            if(mp[half]!=mp[rem]){
                return false;
            }
        }
        return true;
    }
};