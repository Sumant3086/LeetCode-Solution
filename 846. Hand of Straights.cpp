// 846. Hand of Straights
// Solved
// Medium
// Topics
// Companies
// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

// Example 1:

// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
// Example 2:

// Input: hand = [1,2,3,4,5], groupSize = 4
// Output: false
// Explanation: Alice's hand can not be rearranged into groups of 4.

 

// Constraints:

// 1 <= hand.length <= 104
// 0 <= hand[i] <= 109
// 1 <= groupSize <= hand.length


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;//possible
        }
        unordered_map<int,int>count;
        for(int card:hand){
            count[card]++;//count
        }
        vector<int>sortedKeys;
        for(auto& pair:count){
            sortedKeys.push_back(pair.first);//unique card values
        }
        sort(sortedKeys.begin(),sortedKeys.end());//sort

        for(int key:sortedKeys){  //form consecutive group
            if(count[key]>0){  //if this card is still available
                int startCount=count[key];
                for(int i=key;i<key+groupSize;i++){  //check and form a group starting from key
                    if(count[i]<startCount){
                        return false;
                    }
                    count[i]-=startCount;
                }
            }
        }
        return true;
    }
};