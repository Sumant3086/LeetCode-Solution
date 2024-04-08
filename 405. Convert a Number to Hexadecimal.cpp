// 405. Convert a Number to Hexadecimal
// Solved
// Easy
// Topics
// Companies
// Given an integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

// All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

// Note: You are not allowed to use any built-in library method to directly solve this problem.

 

// Example 1:

// Input: num = 26
// Output: "1a"
// Example 2:

// Input: num = -1
// Output: "ffffffff"
 

// Constraints:

// -231 <= num <= 231 - 1

class Solution {
public:
    string toHex(int num) {
        if(num==0){
            return "0";
        }
        char hexDigits[]="0123456789abcdef";
        string result=""; 
        unsigned int unsignedNum=num & 0xFFFFFFFF;

        while(unsignedNum!=0){ 
            int digit=unsignedNum & 0xF;
            result=hexDigits[digit]+result; 
            unsignedNum>>=4;
        }
        return result;
        }
};