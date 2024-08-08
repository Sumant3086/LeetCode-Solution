// 273. Integer to English Words
// Solved
// Hard
// Topics
// Companies
// Hint
// Convert a non-negative integer num to its English words representation.

 

// Example 1:

// Input: num = 123
// Output: "One Hundred Twenty Three"
// Example 2:

// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"
// Example 3:

// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

// Constraints:

// 0 <= num <= 231 - 1



class Solution {
public:
    const vector<string>belowTen={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    const vector<string>belowTwenty={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    const vector<string>belowHundred={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string numberToWords(int num){
        if(num==0){
            return "Zero";
        }
        return convertToWords(num);
    }
    private:
    string convertToWords(int num){
    if(num<10){
        return belowTen[num];
    }
    if(num<20){
        return belowTwenty[num-10];
    }
    if(num<100){
        return belowHundred[num/10]+(num%10 ?" "+convertToWords(num%10):"");
    }
    if(num<1000){
        return convertToWords(num/100)+" Hundred"+(num%100?" "+convertToWords(num%100):"");
    }
    if(num<1000000){
        return convertToWords(num/1000)+" Thousand"+(num%1000?" "+convertToWords(num%1000):"");
    }
    if(num<1000000000){
        return convertToWords(num/1000000)+" Million"+(num%1000000?" "+convertToWords(num%1000000):"");
    }
    return convertToWords(num/1000000000)+" Billion"+(num%1000000000?" "+convertToWords(num % 1000000000):"");
    }
};