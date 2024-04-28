// 3131. Find the Integer Added to Array I
// Solved
// Easy
// Companies
// Hint
// You are given two arrays of equal length, nums1 and nums2.

// Each element in nums1 has been increased (or decreased in the case of negative) by an integer, represented by the variable x.

// As a result, nums1 becomes equal to nums2. Two arrays are considered equal when they contain the same integers with the same frequencies.

// Return the integer x.

 

// Example 1:

// Input: nums1 = [2,6,4], nums2 = [9,7,5]

// Output: 3

// Explanation:

// The integer added to each element of nums1 is 3.

// Example 2:

// Input: nums1 = [10], nums2 = [5]

// Output: -5

// Explanation:

// The integer added to each element of nums1 is -5.

// Example 3:

// Input: nums1 = [1,1,1,1], nums2 = [1,1,1,1]

// Output: 0

// Explanation:

// The integer added to each element of nums1 is 0.


class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        // sort(nums2.begin(), nums2.end());
        // sort(nums1.begin(), nums1.end());
        // int diff=0;
        // for(int i=0;i<nums1.size();++i){
        //     diff=nums2[i]-nums1[i];
        // }
        // return diff;
        return *min_element(nums2.begin(), nums2.end()) - *min_element(nums1.begin(), nums1.end());
    }
};