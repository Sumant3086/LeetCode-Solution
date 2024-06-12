// 75. Sort Colors
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.
 

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0;
        int mid=0;
        int end=nums.size()-1;
        while(mid<=end){
            switch(nums[mid]){
            case 0:
            swap(nums,start,mid);
            mid++;
            start++;
            break;

            case 1:
            mid++;
            break; 
            
            case 2:
            swap(nums,mid,end);
            end--;
            break;

            }
        }
    }
        private:
         void swap(vector<int>&arr,int p1,int p2){
                int temp=arr[p1];
                arr[p1]=arr[p2];
                arr[p2]=temp;

            }
        
};