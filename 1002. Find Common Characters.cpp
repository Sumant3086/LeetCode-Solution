
// Code
// Testcase
// Testcase
// Test Result
// 1002. Find Common Characters
// Solved
// Easy
// Topics
// Companies
// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

// Example 1:

// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]
// Example 2:

// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]
 

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of lowercase English letters.

// class Solution {
// public:
//     vector<string> commonChars(vector<string>& words) {
//         vector<string> res;
//         for(char ch='a';ch<='z';ch++){
//             int minCount=INT_MAX;
//             for(string word:words){
//                 int count=0;
//                 for(char c:word){
//                     if(c==ch){
//                         count++;
//                     }
//                 }
//                 minCount=min(minCount,count);
//             }
//             for(int i=0;i<minCount;i++){
//                 res.push_back(string(1,ch));
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        int min=101;
        int index;
        vector<string> ans;
        for(int i=0;i<n;i++) {
            if(words[i].size()<min){
                min=words[i].size();
                index=i;
            }
        }
        for(int i=0;i<min;i++){
            char c=words[index][i];
            bool present=true;
            for(int j=0;j<n;j++){
                if(words[j].find(c)==string::npos){
                    present=false;
                    break;
                }else{
                    if(j!=index){
                        words[j][words[j].find(c)]='0';
                    }
                }
            }
            if(present)ans.push_back(string(1,c));
        }        
        return ans;
    }
};