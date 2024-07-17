// 1717. Maximum Score From Removing Substrings
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a string s and two integers x and y. You can perform two types of operations any number of times.

// Remove substring "ab" and gain x points.
// For example, when removing "ab" from "cabxbae" it becomes "cxbae".
// Remove substring "ba" and gain y points.
// For example, when removing "ba" from "cabxbae" it becomes "cabxe".
// Return the maximum points you can gain after applying the above operations on s.

 

// Example 1:

// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19
// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
// - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
// - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
// Total score = 5 + 4 + 5 + 5 = 19.
// Example 2:

// Input: s = "aabbaaxybbaabb", x = 5, y = 4
// Output: 20
 

// Constraints:

// 1 <= s.length <= 105
// 1 <= x, y <= 104
// s consists of lowercase English letters.

// class Solution {
// public:
// string removeSubstr(string &s,string &matchStr){
//     stack<char>st;
//     for(char &ch:s){
//         if(ch==matchStr[1] && !st.empty() && st.top()==matchStr[0]){
//             st.pop();
//         }else{
//             st.push(ch);
//         }
//     }
//     string temp;
//     while(!st.empty()){
//         temp.push_back(st.top());
//         st.pop();
//     }
//     reverse(begin(temp),end(temp));
//     return temp;
// }
//     int maximumGain(string s, int x, int y) {
//         int n=s.length();
//         int score=0;
//         string maxStr=(x>y)?"ab":"ba";
//         string minStr=(x>y)?"ba":"ab";
//         string firstTemp=removeSubstr(s,maxStr);
//         int len=firstTemp.length();
//         int charRemoved=(n-len);
//         score+=(charRemoved/2)*max(x,y);
//         string secondTemp=removeSubstr(firstTemp,minStr);
//         charRemoved=len-secondTemp.length();
//         score+=(charRemoved/2)*min(x,y);
//         return score;
//     }
// };

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x<y){
            int temp=x;
            x=y;
            y=temp;
            reverse(s.begin(),s.end());
        }
        int aCount=0,bCount=0,totalPoints=0;
        for(int i=0;i<s.size();++i){
            char currentChar=s[i];
            if(currentChar=='a'){
                ++aCount;
            }else if(currentChar=='b'){
                if(aCount>0){
                    --aCount;
                    totalPoints+=x;
                }else{
                    ++bCount;
                }
            }else{
                totalPoints+=min(bCount,aCount)*y;
                aCount=bCount = 0;
            }
        }
        totalPoints+=min(bCount,aCount)*y;
        return totalPoints;
    }
};
