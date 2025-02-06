// 1726. Tuple with Same Product
// Medium
// Topics
// Companies
// Hint
// Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

 

// Example 1:

// Input: nums = [2,3,4,6]
// Output: 8
// Explanation: There are 8 valid tuples:
// (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
// (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
// Example 2:

// Input: nums = [1,2,4,5,10]
// Output: 16
// Explanation: There are 16 valid tuples:
// (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
// (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
// (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
// (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 104
// All elements in nums are distinct.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 44.4K
// Submissions
// 68.6K
// Acceptance Rate
// 64.7%
// Topics
// Array
// Hash Table
// Counting
// Companies
// Hint 1
// Note that all of the integers are distinct. This means that each time a product is formed it must be formed by two unique integers.
// Hint 2
// Count the frequency of each product of 2 distinct numbers. Then calculate the permutations formed.
// Discussion (61)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
    int n=nums.size();
        unordered_map<int,int>proMp;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                proMp[nums[i]*nums[j]]++;
            }
        }
        for(auto[val,freq]:proMp){
            int equal=(freq-1)*freq/2;
            count+=8*equal;
        }
        return count;
    }
};