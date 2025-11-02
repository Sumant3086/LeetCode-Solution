// 1399. Count Largest Group
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer n.

// We need to group the numbers from 1 to n according to the sum of its digits. For example, the numbers 14 and 5 belong to the same group, whereas 13 and 3 belong to different groups.

// Return the number of groups that have the largest size, i.e. the maximum number of elements.

 

// Example 1:

// Input: n = 13
// Output: 4
// Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
// [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
// There are 4 groups with largest size.
// Example 2:

// Input: n = 2
// Output: 2
// Explanation: There are 2 groups [1], [2] of size 1.
 

// Constraints:

// 1 <= n <= 104
 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 180,072/240.9K
// Acceptance Rate
// 74.8%
// Topics
// icon
// Companies
// Hint 1
// Discussion (206)

class Solution {
public:
    int digitS(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int>possSum(37);
        for(int i=1;i<=n;i++){
            possSum[digitS(i)]++;
        }
        int maxi=0;
        int count=0;
        for(int i:possSum){
            if(i>maxi){
                maxi=i;
                count=1;
            }else if(i==maxi){
                count++;
            }
        }
        return count;
    }
};