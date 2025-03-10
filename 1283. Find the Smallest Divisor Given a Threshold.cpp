// 1283. Find the Smallest Divisor Given a Threshold
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

// The test cases are generated so that there will be an answer.

 

// Example 1:

// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
// Example 2:

// Input: nums = [44,22,33,11,1], threshold = 5
// Output: 44
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// 1 <= nums[i] <= 106
// nums.length <= threshold <= 106
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 256.5K
// Submissions
// 412.2K
// Acceptance Rate
// 62.2%
// Topics
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (51)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

class Solution {
public:
bool isPossible(vector<int>& nums,int threshold,int mid){
    int sum=0;
    for(int i:nums){
        sum+=ceil((double)i/mid);
    }
    if(sum<=threshold){
        return true;
    }else{
        return false;
    } 
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int start=1;
        int end=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(isPossible(nums,threshold,mid)){
                end=mid-1;
                ans=mid;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};