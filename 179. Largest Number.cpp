// 179. Largest Number
// Attempted
// Medium
// Topics
// Companies
// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

 

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 551.1K
// Submissions
// 1.5M
// Acceptance Rate
// 38.0%
// Topics
// Array
// String
// Greedy
// Sorting
// Companies
// Similar Questions
// Discussion (121)

// class Solution {
// public:
//     string largestNumber(vector<int>& nums) {
//         vector<int>digits;
//         string res="";
//         for(int num:nums){
//             res+=to_string(num);
//         }
//         for(char ch:res){
//             digits.push_back(ch-'0');
//         }
//         sort(digits.rbegin(),digits.rend());
//         string ans="";
//         for(int digit:digits){
//             ans+=to_string(digit);
//         }
//         return ans;
//     }
// };//this will give error 



class Solution {
public: 
    static bool customCompare(const string &a,const string &b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums){ 
        vector<string>numStrings;
        for(int num:nums){
            numStrings.push_back(to_string(num));
        } 
        sort(numStrings.begin(),numStrings.end(),customCompare);
        if(numStrings[0]=="0"){
            return "0";
        }
        string result="";
        for(const string &numStr:numStrings){
            result+=numStr;
        }
        return result;
    }
};


