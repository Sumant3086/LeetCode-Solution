
// Code
// Testcase
// Test Result
// Test Result
// 4. Median of Two Sorted Arrays
// Solved
// Hard
// Topics
// Companies
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        int med1=0;
        int med2=0;
        for(int count=0;count<=(n+m)/2;count++){
            med2=med1;
            if(i!=n && j!=m){
                if(nums1[i]>nums2[j]){
                    med1=nums2[j++];
                }else{
                    med1=nums1[i++];
                }
            }else if(i<n){
                med1=nums1[i++];
            }else{
                med1=nums2[j++];
            }
        }
        if((n+m)%2==1){
            return static_cast<double>(med1);
        }else{
            double ans=static_cast<double>(med1)+static_cast<double>(med2);
            return ans/2.0;
        }
    }
};