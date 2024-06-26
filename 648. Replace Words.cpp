// 648. Replace Words
// Solved
// Medium
// Topics
// Companies
// In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

// Return the sentence after the replacement.

 

// Example 1:

// Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
// Example 2:

// Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
// Output: "a a b c"
 

// Constraints:

// 1 <= dictionary.length <= 1000
// 1 <= dictionary[i].length <= 100
// dictionary[i] consists of only lower-case letters.
// 1 <= sentence.length <= 106
// sentence consists of only lower-case letters and spaces.
// The number of words in sentence is in the range [1, 1000]
// The length of each word in sentence is in the range [1, 1000]
// Every two consecutive words in sentence will be separated by exactly one space.
// sentence does not have leading or trailing spaces.


// class Solution {
// public:
//     string replaceWords(vector<string>& dictionary, string sentence) {
//         set<string>s;
//         for(int i=0;i<dictionary.size();i++){
//             s.insert(dictionary[i]);
//         }
//         string temp="";
//         string ans="";
//         vector<string>str;
//         for(int i=0;i<sentence.size();i++){
//             if(sentence[i]==' '){
//                 str.push_back(temp);
//                 temp="";
//             }else{
//                 temp+=sentence[i];
//             }
//         }
//         str.push_back(temp);
//         temp="";
//         for(auto word:str){
//             string wholeWord=word;
//             for(int i=0;i<=word.size();i++){
//                 temp=word.substr(0,i);
//                 if(s.find(temp)!=s.end()){
//                     break;
//                 }
//             }
//             ans+=temp+" ";
//             temp="";
//         }
//         ans.pop_back();
//         return ans;
//     }
// };

// auto init = []() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     return 'c';
// }();


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
         unordered_set<string> rootSet(dictionary.begin(), dictionary.end());
        
        stringstream ss(sentence);
        string temp;
        vector<string> words;
        
        while (ss >> temp) {
            words.push_back(temp);
        }
        
        for (auto& word : words) {
            int n = word.size();
            string temp = "";
            for (int i = 0; i < n; i++) {
                temp += word[i];
                if (rootSet.count(temp)) {
                    word = temp;
                    break;
                }
            }
        }
        
        string res = "";
        for (auto& word : words) {
            res += word + " ";
        }
        
        if (!res.empty()) {
            res.pop_back();
        }
        
        return res;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();