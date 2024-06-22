// 1248. Count Number of Nice Subarrays
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

 

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.
// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16
 

// Constraints:

// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10^5
// 1 <= k <= nums.length


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
           
        unordered_map<int,int>map;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                nums[i]=1;
            }else{
                nums[i]=0;
            }
        }
            int sum=0;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
            if(sum==k)
                count++;
            if(map.find(sum-k)!=map.end())
            count+=map[sum-k];
            map[sum]++;
            }
            return count;
    }
};