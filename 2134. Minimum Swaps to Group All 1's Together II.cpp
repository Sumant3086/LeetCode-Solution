// 2134. Minimum Swaps to Group All 1's Together II
// Solved
// Medium
// Topics
// Companies
// Hint
// A swap is defined as taking two distinct positions in an array and swapping the values in them.

// A circular array is defined as an array where we consider the first element and the last element to be adjacent.

// Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

 

// Example 1:

// Input: nums = [0,1,0,1,1,0,0]
// Output: 1
// Explanation: Here are a few of the ways to group all the 1's together:
// [0,0,1,1,1,0,0] using 1 swap.
// [0,1,1,1,0,0,0] using 1 swap.
// [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
// There is no way to group all 1's together with 0 swaps.
// Thus, the minimum number of swaps required is 1.
// Example 2:

// Input: nums = [0,1,1,1,0,0,1,1,0]
// Output: 2
// Explanation: Here are a few of the ways to group all the 1's together:
// [1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
// [1,1,1,1,1,0,0,0,0] using 2 swaps.
// There is no way to group all 1's together with 0 or 1 swaps.
// Thus, the minimum number of swaps required is 2.
// Example 3:

// Input: nums = [1,1,0,0,1]
// Output: 0
// Explanation: All the 1's are already grouped together due to the circular property of the array.
// Thus, the minimum number of swaps required is 0.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.


static const int fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    return 0;
}();
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int& x:nums) cnt+=x;
        if(cnt==n) return 0;
        int swaps=n;
        int l=0;
        int r=0;
        int curr=0;
        while(l<n){
            while(r>=l?r-l<cnt:n-l+r<cnt){
                curr+=nums[r];
                r=(r+1)%n;
            }
            swaps=min(swaps,cnt-curr);
            curr-=nums[l];
            l++;
        }
        return swaps;
    }
};