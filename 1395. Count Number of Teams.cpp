// 1395. Count Number of Teams
// Solved
// Medium
// Topics
// Companies
// Hint
// There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

// You have to form a team of 3 soldiers amongst them under the following rules:

// Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
// A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
// Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

// Example 1:

// Input: rating = [2,5,3,4,1]
// Output: 3
// Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
// Example 2:

// Input: rating = [2,1,3]
// Output: 0
// Explanation: We can't form any team given the conditions.
// Example 3:

// Input: rating = [1,2,3,4]
// Output: 4
 

// Constraints:

// n == rating.length
// 3 <= n <= 1000
// 1 <= rating[i] <= 105
// All the integers in rating are unique.

class Solution {
public:
    int numTeams(vector<int>& ratings) {
        int maxR=0;
        for(int r:ratings){
            maxR=max(r,maxR);
        }
        vector<int>leftBit(maxR+1,0);
        vector<int>rightBit(maxR+1,0);
        for(int r:ratings){
            updateBit(rightBit,r,1);
        }
        int teams=0;
        for(int currR:ratings){
            updateBit(rightBit,currR,-1);
            int smallRL=getPrefixSum(leftBit,currR-1);
            int smallRR=getPrefixSum(rightBit,currR-1);

            int largeRL=getPrefixSum(leftBit,maxR)-getPrefixSum(leftBit,currR);
            int largeRR=getPrefixSum(rightBit,maxR)-getPrefixSum(rightBit,currR);

            teams+=(smallRL*largeRR);
            teams+=(largeRL*smallRR);

            updateBit(leftBit,currR,1);
        }
        return teams;
    }
    private:
    void updateBit(vector<int>& Bit,int idx,int val){
        while(idx<Bit.size()){
            Bit[idx]+=val;
            idx+=idx & (-idx);
        }
    }
    int getPrefixSum(vector<int>& Bit,int idx){
        int sum=0;
        while(idx>0){
            sum+=Bit[idx];
            idx-=idx & (-idx);
        }
        return sum;
    }
};