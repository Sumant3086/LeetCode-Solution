// 1004. Max Consecutive Ones III
// Solved
// Medium
// Topics
// Companies
// Hint
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// 0 <= k <= nums.length

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 812.2K
// Submissions
// 1.3M
// Acceptance Rate
// 64.9%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Hint 4
// Similar Questions
// Discussion (79)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int maxL=0;
        int zero=0;
        for(int r=0;r<n;r++){
            if(nums[r]==0){
                zero++;
            }
            while(zero>k){
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
            maxL=max(maxL,r-l+1);
        }
        return maxL;
    }
};

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n=nums.size();
//         int maxL=0;
//         for(int i=0;i<n;i++){
//             int zero=0;
//             for(int j=i;j<n;j++){
//                 if(nums[j]==0){
//                     zero++;
//                 }
//                 if(zero<=k){
//                     maxL=max(maxL,j-i+1);
//                 }else{
//                     break;
//                 }
//             }
//         }
//         return maxL;
//     }
// };