// 1813. Sentence Similarity III
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

// Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.

// For example,

// s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
// s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
// Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

 

// Example 1:

// Input: sentence1 = "My name is Haley", sentence2 = "My Haley"

// Output: true

// Explanation:

// sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

// Example 2:

// Input: sentence1 = "of", sentence2 = "A lot of words"

// Output: false

// Explanation:

// No single sentence can be inserted inside one of the sentences to make it equal to the other.

// Example 3:

// Input: sentence1 = "Eating right now", sentence2 = "Eating"

// Output: true

// Explanation:

// sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.

 

// Constraints:

// 1 <= sentence1.length, sentence2.length <= 100
// sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
// The words in sentence1 and sentence2 are separated by a single space.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 80.4K
// Submissions
// 173.8K
// Acceptance Rate
// 46.3%
// Topics
// Companies
// Hint 1
// Hint 2
// Discussion (122)

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss1(s1), ss2(s2);
        string word;
        vector<string>s1Words,s2Words;
        while(ss1>>word)
            s1Words.push_back(word);
        while(ss2>>word)
            s2Words.push_back(word);
        int start=0;
        int ends1=s1Words.size()-1;
        int ends2=s2Words.size()-1;
        if(s1Words.size() > s2Words.size()) 
            return areSentencesSimilar(s2, s1);
        while(start<s1Words.size() && s1Words[start]==s2Words[start])
            ++start;
        while(ends1>=0 && s1Words[ends1]==s2Words[ends2]){
            --ends1;
            --ends2;
        }
        return ends1<start;
    }
};