// 213. House Robber II
// Solved
// Medium
// Topics
// Companies
// Hint
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 915.4K
// Submissions
// 2.1M
// Acceptance Rate
// 43.0%
// Topics
// Companies
// Hint 1
// Similar Questions
// Discussion (87)
// Type comment here... (Markdown supported)

// Choose a type


class Solution {
public:
    int forLinear(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        int prev2=nums[0];
        int prev=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int curr=max(prev,nums[i]+prev2);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>&nums){
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(forLinear(temp1),forLinear(temp2));
    }
};