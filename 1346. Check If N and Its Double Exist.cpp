// 1346. Check If N and Its Double Exist
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an array arr of integers, check if there exist two indices i and j such that :

// i != j
// 0 <= i, j < arr.length
// arr[i] == 2 * arr[j]
 

// Example 1:

// Input: arr = [10,2,5,3]
// Output: true
// Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
// Example 2:

// Input: arr = [3,1,7,11]
// Output: false
// Explanation: There is no i and j that satisfy the conditions.
 

// Constraints:

// 2 <= arr.length <= 500
// -103 <= arr[i] <= 103
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 445.8K
// Submissions
// 1.1M
// Acceptance Rate
// 39.3%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Similar Questions
// Discussion (133)

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>seen;
        for(int num:arr){
            if(seen.count(2*num) || (num%2==0 && seen.count(num/2))){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};