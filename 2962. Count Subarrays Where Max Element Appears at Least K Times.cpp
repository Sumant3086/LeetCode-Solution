// 2962. Count Subarrays Where Max Element Appears at Least K Times
// Solved
// Medium
// Topics
// Companies
// You are given an integer array nums and a positive integer k.

// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

// A subarray is a contiguous sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,3,2,3,3], k = 2
// Output: 6
// Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
// Example 2:

// Input: nums = [1,4,2,1], k = 3
// Output: 0
// Explanation: No subarray contains the element 4 at least 3 times.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106
// 1 <= k <= 105
auto init = []()
{
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);            
    cout.tie(nullptr);           
    return 'c';                  
}();
// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k) {
//         int max=*max_element(nums.begin(),nums.end());
//         int count=0;
//         int left=0;
//         int right=0;
//         long long ans=0;
//         int n=nums.size();
//         unordered_map<int,int>map;
//         while(right<n){
//             map[nums[right]]++;
//             while(map[max]>=k){
//                 ans+=n-right;
//                 map[nums[left]]--;
//                 left++;
//             }
//             right++;
//         }
//         return ans;
//     }
// };

 class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxi = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        long long ans = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == maxi) cnt++;
            if(cnt == k){
                while(cnt == k){
                    ans += n-i;
                    if(nums[j] == maxi) cnt--;
                    j++;
                }
            }
        }
        return ans;
    }
};