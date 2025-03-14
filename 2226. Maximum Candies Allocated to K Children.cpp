// 2226. Maximum Candies Allocated to K Children
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

// You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

// Return the maximum number of candies each child can get.

 

// Example 1:

// Input: candies = [5,8,6], k = 3
// Output: 5
// Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
// Example 2:

// Input: candies = [2,5], k = 11
// Output: 0
// Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.
 

// Constraints:

// 1 <= candies.length <= 105
// 1 <= candies[i] <= 107
// 1 <= k <= 1012

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 139.4K
// Submissions
// 284.8K
// Acceptance Rate
// 48.9%
// Topics
// Array
// Binary Search
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (207)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

// 1.6K


// 207





class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int left=1;
            int right=*max_element(candies.begin(),candies.end());
            while(left<right){
                int mid=(left+right+1)/2;
                long long count=0;
                for(int i:candies)count+=i/mid;
                if(count>=k)left=mid;
                else right=mid-1;
            }
            long long count=0;
            for(int i:candies)count+=i/left;
            return count>=k?left:0;
        }
    };