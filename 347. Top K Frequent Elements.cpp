// 347. Top K Frequent Elements
// Solved
// Medium
// Topics
// Companies
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.
 

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 2.6M
// Submissions
// 4.1M
// Acceptance Rate
// 64.0%
// Topics
// Array
// Hash Table
// Divide and Conquer
// Sorting
// Heap (Priority Queue)
// Bucket Sort
// Counting
// Quickselect
// Companies
// Similar Questions
// Discussion (228)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int>mp;
            vector<int>ans; 
            for(int i:nums){
                mp[i]++;
            }
            priority_queue<pair<int,int>>pq;
            for(auto i:mp){
                pq.push({i.second,i.first});
            }
            for(int i=0;i<k;i++){  
                ans.push_back(pq.top().second);
                pq.pop();
            }
            return ans;
        }
    };