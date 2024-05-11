// 786. K-th Smallest Prime Fraction
// Solved
// Medium
// Topics
// Companies
// You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

// For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

// Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

 

// Example 1:

// Input: arr = [1,2,3,5], k = 3
// Output: [2,5]
// Explanation: The fractions to be considered in sorted order are:
// 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
// The third fraction is 2/5.
// Example 2:

// Input: arr = [1,7], k = 1
// Output: [1,7]
 

// Constraints:

// 2 <= arr.length <= 1000
// 1 <= arr[i] <= 3 * 104
// arr[0] == 1
// arr[i] is a prime number for i > 0.
// All the numbers of arr are unique and sorted in strictly increasing order.
// 1 <= k <= arr.length * (arr.length - 1) / 2


class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        double l=0;
        double r=1.0;
        while(l<r){
            double m=(l+r)/2;//middle value
            double maxF=0.0;//tracking
            int totSmall=0,numIdx=0,denIdx=0;
            int j=1;
            for(int i=0;i<n-1;i++){
                while(j<n && arr[i]>=m*arr[j]){
                    j++;
                }
                totSmall+=(n-j);
                if(j==n)break;//if we have exhausted the array,then break
                double fraction=static_cast<double>(arr[i])/arr[j];
                if(fraction>maxF){
                    numIdx=i;
                    denIdx=j;
                    maxF=fraction;//updating indexes
                }
            }
            if(totSmall==k){
                return {arr[numIdx],arr[denIdx]};
            }else if(totSmall>k){
                r=m;
            }else{
                l=m;
            }
        }  
        return {};
    }
};