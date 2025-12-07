class Solution {
public:
    int countOdds(int low, int high) {
        return (high-low)/2+ (low%2 || high%2);
    }
};

// class Solution {
// public:
//     int countOdds(int low, int high) {
//         return (high+1)/2-low/2;
//     }
// };