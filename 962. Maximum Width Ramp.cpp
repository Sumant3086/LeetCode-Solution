// 962. Maximum Width Ramp
// Solved
// Medium
// Topics
// Companies
// A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

// Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

 

// Example 1:

// Input: nums = [6,0,8,2,1,5]
// Output: 4
// Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
// Example 2:

// Input: nums = [9,8,1,0,1,9,4,0,4,1]
// Output: 7
// Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
 

// Constraints:

// 2 <= nums.length <= 5 * 104
// 0 <= nums[i] <= 5 * 104


class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>rightMax(n);
        rightMax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],nums[i]);
        }
        int left=0,right=0;
        int maxWidth=0;
        while(right<n){
            while(left<right && nums[left]>rightMax[right]){
                left++;
            }
            maxWidth=max(maxWidth,right-left);
            right++;
        }
        return maxWidth;
    }
};



 static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         int n=nums.size();
//         int maxWidth=0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[j]>=nums[i]){
//                     maxWidth=max(maxWidth,j-i);
//                 }
//             }
//         }
//         return maxWidth;
//     }
// };TLE