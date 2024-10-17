// 670. Maximum Swap
// Solved
// Medium
// Topics
// Companies
// You are given an integer num. You can swap two digits at most once to get the maximum valued number.

// Return the maximum valued number you can get.

 

// Example 1:

// Input: num = 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.
// Example 2:

// Input: num = 9973
// Output: 9973
// Explanation: No swap.
 

// Constraints:

// 0 <= num <= 108

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 321.2K
// Submissions
// 641K
// Acceptance Rate
// 50.1%
// Topics
// Companies
// Similar Questions
// Discussion (142)

class Solution {
public:
    int maximumSwap(int num) {
        string str=to_string(num);
        int n=str.length();
        vector<int>maxRight(n);
        maxRight[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            int rightMaxIdx=maxRight[i+1];
            int rightMaxEle=str[rightMaxIdx];
            maxRight[i]=(str[i]>rightMaxEle)?i:rightMaxIdx;
        }
        for(int i=0;i<n;i++){
            int maxRightIdx=maxRight[i];
            int maxRightEle=str[maxRightIdx];
            if(str[i]<maxRightEle){
                swap(str[i],str[maxRightIdx]);
                return stoi(str);
            }
        }
        return num;
    }
};