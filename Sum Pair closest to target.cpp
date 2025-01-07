// Sum Pair closest to target
// Difficulty: EasyAccuracy: 44.75%Submissions: 37K+Points: 2
// Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is closest to target.
// Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

// Examples:

// Input: arr[] = [10, 30, 20, 5], target = 25
// Output: [5, 20]
// Explanation: As 5 + 20 = 25 is closest to 25.
// Input: arr[] = [5, 2, 7, 1, 4], target = 10
// Output: [2, 7]
// Explanation: As (4, 7) and (2, 7) both are closest to 10, but absolute difference of (2, 7) is 5 and (4, 7) is 3. Hence, [2, 7] has maximum absolute difference and closest to target. 
// Input: arr[] = [10], target = 10
// Output: []
// Explanation: As the input array has only 1 element, return an empty array.
// Constraints:
// 1 <= arr.size() <= 2*105
// 0 <= target<= 2*105
// 0 <= arr[i] <= 105

// Company Tags
// Ola Cabs
// Topic Tags
// Related Articles
// Expected Complexities
// If you are faci

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here 
        vector<int>res;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(n==1)return {};
        int left=0;
        int right=n-1;
        int ans1=0;
        int ans2=0;
        int diff;
        int mini=INT_MAX;
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum==target){
                return {arr[left],arr[right]};
            }else{
                int rem=abs(target-sum);
                if(mini>rem){
                    ans1=arr[left];
                    ans2=arr[right];
                    mini=rem;
                    diff=arr[right]-arr[left];
                }else if(mini==rem){
                    int d=arr[right]-arr[left];
                    if(diff<d){
                        ans1=arr[left];
                        ans2=arr[right];
                        diff=d;
                    }
                }
            }
            if(sum<target){
                left++;
            }else{
                right--;
            }
        }
        return {ans1,ans2};
    }
};