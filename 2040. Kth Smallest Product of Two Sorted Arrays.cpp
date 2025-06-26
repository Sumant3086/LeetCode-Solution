// 2040. Kth Smallest Product of Two Sorted Arrays
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.
 

// Example 1:

// Input: nums1 = [2,5], nums2 = [3,4], k = 2
// Output: 8
// Explanation: The 2 smallest products are:
// - nums1[0] * nums2[0] = 2 * 3 = 6
// - nums1[0] * nums2[1] = 2 * 4 = 8
// The 2nd smallest product is 8.
// Example 2:

// Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
// Output: 0
// Explanation: The 6 smallest products are:
// - nums1[0] * nums2[1] = (-4) * 4 = -16
// - nums1[0] * nums2[0] = (-4) * 2 = -8
// - nums1[1] * nums2[1] = (-2) * 4 = -8
// - nums1[1] * nums2[0] = (-2) * 2 = -4
// - nums1[2] * nums2[0] = 0 * 2 = 0
// - nums1[2] * nums2[1] = 0 * 4 = 0
// The 6th smallest product is 0.
// Example 3:

// Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
// Output: -6
// Explanation: The 3 smallest products are:
// - nums1[0] * nums2[4] = (-2) * 5 = -10
// - nums1[0] * nums2[3] = (-2) * 4 = -8
// - nums1[4] * nums2[0] = 2 * (-3) = -6
// The 3rd smallest product is -6.
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 5 * 104
// -105 <= nums1[i], nums2[j] <= 105
// 1 <= k <= nums1.length * nums2.length
// nums1 and nums2 are sorted.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 74,351/151.5K
// Acceptance Rate
// 49.1%
// Topics
// Array
// Binary Search
// icon
// Companies
// Hint 1
// Hint 2
// Similar Questions
// Discussion (131)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.

// 1.1K


// 131




class Solution {
public:
    long long helper(vector<int>& nums1,vector<int>&nums2,long long mid){
        long long count=0;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++){
            long long curr=nums1[i];
            if(curr>0){
                int low=0;
                int high=m-1;
                int idx=-1;
                while(low<=high){
                    int mid2=low+(high-low)/2;
                    if(1LL*curr*nums2[mid2]<=mid){
                        idx=mid2;
                        low=mid2+1;
                    }else{
                        high=mid2-1;
                    }
                }
                count+=(idx+1);
            }else if(curr<0){
                int low=0;
                int high=m-1;
                int idx=m;
                while(low<=high){
                    long long mid2=(low+high)/2;
                    if(1LL*curr*nums2[mid2]<=mid){
                        idx=mid2;
                        high=mid2-1;
                    }else{
                        low=mid2+1;
                    }
                }
                count+=(m-idx);
            }else{ 
                if(0<=mid){
                    count+=m;
                }
            }
        }
        return count;
    } 
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low=-1e10;
        long long high=1e10;
        // long long s1=*min_element(nums1.begin(),nums1.end());
        // long long s2=*min_element(nums2.begin(),nums2.end());
        // long long l1=*max_element(nums1.begin(),nums1.end());
        // long long l2=*max_element(nums2.begin(),nums2.end());
        long long res=0;
        // long long p1=s1*s2;
        // long long p2=s1*l2;
        // long long p3=l1*s2;
        // long long p4=l1*l2;
        // long long low1=min(p1,p2);
        // long long low2=min(p3,p4);
        // long long high1=max(p1,p2);
        // long long high2=max(p3,p4);
        // long long low=min(low1,low2);
        // long long high=max(high1,high2);
        cout<<low<<" "<<high<<endl;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long solve=helper(nums1,nums2,mid);
            if(solve>=k){
                res=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return res;        
    }
};