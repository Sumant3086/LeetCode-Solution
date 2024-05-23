// 2597. The Number of Beautiful Subsets
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an array nums of positive integers and a positive integer k.

// A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

// Return the number of non-empty beautiful subsets of the array nums.

// A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

 

// Example 1:

// Input: nums = [2,4,6], k = 2
// Output: 4
// Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
// It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
// Example 2:

// Input: nums = [1], k = 1
// Output: 1
// Explanation: The beautiful subset of the array nums is [1].
// It can be proved that there is only 1 beautiful subset in the array [1].
 

// Constraints:

// 1 <= nums.length <= 20
// 1 <= nums[i], k <= 1000


// class Solution {
// public:
//     int beautifulSubsets(vector<int>& nums, int k) {
//         int count=0;
//         unordered_map<int,int>visited;
//         explore(nums,k,0,visited,count);
//         return count-1;  //to exclude the empty set
//     }
//     int count;
//     void explore(vector<int>& nums,int k,int idx,unordered_map<int,int>& visited,int& count){
//         if(idx==nums.size()){
//             count++;
//             return;
//         }
//         int element=nums[idx];
//         if(visited.find(element-k)==visited.end() &&
//            visited.find(element+k)==visited.end()){
//             visited[element]++;
//             explore(nums,k,idx+1,visited,count);
//             visited[element]--;
//             if(visited[element]==0){
//                 visited.erase(element);
//             }
//         }
//         explore(nums,k,idx+1,visited,count);
//     }
// };

class Solution {
public:
    int helper(vector<int>& nums, int k) {
        if (nums.size() == 1) return 2;
        if (nums.size() == 0) return 1;
        vector<int> s;
        int x = nums[nums.size()-1] - k;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != x) {
                s.push_back(nums[i]);
            }
        }
        nums.pop_back();
        if (nums.size() == s.size()) {
            return helper(nums, k) * 2;
        } else {
            return helper(nums, k) + helper(s, k);
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return helper(nums, k) - 1;
    }
};