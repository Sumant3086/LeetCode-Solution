// 2616. Minimize the Maximum Difference of Pairs
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

// Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

// Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

 

// Example 1:

// Input: nums = [10,1,2,7,1,3], p = 2
// Output: 1
// Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
// The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
// Example 2:

// Input: nums = [4,2,1,2], p = 1
// Output: 0
// Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109
// 0 <= p <= (nums.length)/2

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 90,639/200.4K
// Acceptance Rate
// 45.2%

class Solution {
public:
    bool isP(vector<int>& nums,int p,int mid){
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]<=mid){
                count++;
                i++;
            }
        }
        return count>=p;
    } 
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int res=0;
        int low=0;
        int high=nums.back()-nums.front();
        while(low<=high){
            int mid=(low+high)/2;
            if(isP(nums,p,mid)){
                res=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return res;
    }
};