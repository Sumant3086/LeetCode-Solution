// 912. Sort an Array
// Solved
// Medium
// Topics
// Companies
// Given an array of integers nums, sort the array in ascending order and return it.

// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

// Example 1:

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
// Example 2:

// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessairly unique.
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// -5 * 104 <= nums[i] <= 5 * 104

// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) { 
//         int n=nums.size();    
//         for(int i=0;i<n-1;i++){
//             int min=i;
//             for(int j=i+1;j<n;j++){
//                 if(nums[j]<nums[min]){
//                     min=j; 
//                 }
//             }
//             swap(nums[min],nums[i]);
//         }
//         return nums;
//     }
// }; we will get TLE



// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) { 
//         sort(nums.begin(),nums.end());
//         return nums;
//     }
// };




class Solution {
public:
    void merge(vector<int>& nums,int left,int mid,int right){
        int n1=mid-left+1;
        int n2=right-mid;
        vector<int>L(n1);
        vector<int>R(n2);

        for(int i=0;i<n1;++i)
            L[i]=nums[left+i];
        for(int j=0;j<n2;++j)
            R[j]=nums[mid+1+j];
        int i=0,j=0,k=left;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                nums[k]=L[i];
                ++i;
            }else{
                nums[k]=R[j];
                ++j;
            }
            ++k;
        }
        while(i<n1){
            nums[k]=L[i];
            ++i;
            ++k;
        }
        while(j<n2){
            nums[k]=R[j];
            ++j;
            ++k;
        }
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if(left<right){
            int mid=left+(right-left)/2;
            mergeSort(nums,left,mid);
            mergeSort(nums,mid+1,right);
            merge(nums,left,mid,right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        if (!nums.empty()){
            mergeSort(nums,0,nums.size()-1);
        }
        return nums;
    }
};
