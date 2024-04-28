// 3132. Find the Integer Added to Array II
// Solved
// Medium
// Companies
// Hint
// You are given two integer arrays nums1 and nums2.

// From nums1 two elements have been removed, and all other elements have been increased (or decreased in the case of negative) by an integer, represented by the variable x.

// As a result, nums1 becomes equal to nums2. Two arrays are considered equal when they contain the same integers with the same frequencies.

// Return the minimum possible integer x that achieves this equivalence.

 

// Example 1:

// Input: nums1 = [4,20,16,12,8], nums2 = [14,18,10]

// Output: -2

// Explanation:

// After removing elements at indices [0,4] and adding -2, nums1 becomes [18,14,10].

// Example 2:

// Input: nums1 = [3,5,5,3], nums2 = [7,7]

// Output: 2

// Explanation:

// After removing elements at indices [0,3] and adding 2, nums1 becomes [7,7].

 

// Constraints:

// 3 <= nums1.length <= 200
// nums2.length == nums1.length - 2
// 0 <= nums1[i], nums2[i] <= 1000
// The test cases are generated in a way that there is an integer x such that nums1 can become equal to nums2 by removing two elements and adding x to each element of nums1.

// class Solution {
// public:
//     int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size();
//         sort(nums1.begin(),nums1.end());
//         sort(nums2.begin(),nums2.end());
        
//         int ans=INT_MAX,res=INT_MAX;
//         map<int,int>mp;
//         for(auto x:nums2)mp[x]++;
        
//         int left=-nums1[n-1]+nums2[0];
//         int right=nums2[n-3]-nums1[0];
        
//         for(int i=left;i<=right;i++){
//             map<int,int>mp1;
//             for(int j=0;j<n;j++){
//                 int x=nums1[j]+i;
//                 mp1[x]++;
                
//             }
//             int cnt=0;
//             for(auto [x,y]:mp){
//                 if(mp1[x]<y)cnt++;
//             }
//             if(cnt==0)return i;
//             mp1.clear();
//         }
            
//         return ans;
//     }
// };
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int d=nums2[0]-nums1[2];
        const int n=nums2.size();
        bool ok=true;
        for (int i=1;ok && i<n;++i){
            ok=nums2[i]-nums1[i+2]==d;
        }
        if(ok) return d;
        d=nums2[0]-nums1[1];
        ok=true;
        for(int i=1,j=2,c=0;ok && i<n;++i,++j){
            if(nums2[i]-nums1[j]!=d){
                if(++c>1){
                    ok=false;
                }else{
                    --i;
                }
            }
        }
        if(ok) return d;
        return nums2[0]-nums1[0];        
    }
};