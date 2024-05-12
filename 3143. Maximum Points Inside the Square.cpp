
// Code
// Code Sample
// Code Sample
// Testcase
// Testcase
// Test Result
// 3143. Maximum Points Inside the Square
// Solved
// Medium
// Companies
// Hint
// You are given a 2D array points and a string s where, points[i] represents the coordinates of point i, and s[i] represents the tag of point i.

// A valid square is a square centered at the origin (0, 0), has edges parallel to the axes, and does not contain two points with the same tag.

// Return the maximum number of points contained in a valid square.

// Note:

// A point is considered to be inside the square if it lies on or within the square's boundaries.
// The side length of the square can be zero.
 

// Example 1:



// Input: points = [[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]], s = "abdca"

// Output: 2

// Explanation:

// The square of side length 4 covers two points points[0] and points[1].

// Example 2:



// Input: points = [[1,1],[-2,-2],[-2,2]], s = "abb"

// Output: 1

// Explanation:

// The square of side length 2 covers one point, which is points[0].

// Example 3:

// Input: points = [[1,1],[-1,-1],[2,-2]], s = "ccd"

// Output: 0

// Explanation:

// It's impossible to make any valid squares centered at the origin such that it covers only one point among points[0] and points[1].

 

// Constraints:

// 1 <= s.length, points.length <= 105
// points[i].length == 2
// -109 <= points[i][0], points[i][1] <= 109
// s.length == points.length
// points consists of distinct coordinates.
// s consists only of lowercase English letters.

// class Solution {
// public:
//     int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
//         map<int,multiset<char>>mp;
//         int res=0;
//         for(int i=0;i<points.size();i++){
//             mp[max(abs(points[i][0]),abs(points[i][1]))].insert(s[i]);
//         }
//         set<char>str;
//         for(auto iterate:mp){
//             set<char>ch;
//             for(auto iterate1:iterate.second){
//                 if(ch.count(iterate1)>0 || str.count(iterate1)>0){
//                     return res;
//                 }else{
//                     ch.insert(iterate1);
//                 }
//             }
//             for(auto iterate1:iterate.second){
//                 res++;
//                 str.insert(iterate1);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    
    int check(vector<vector<int>> &points,string &s,int mid){
        set<int> st;
        for(int i=0;i<points.size();i++){
            int a1=abs(points[i][0]),a2=abs(points[i][1]);
            if(a1<mid && a2<mid){
                if(st.find(s[i])!=st.end()){
                    return 0;
                }
                st.insert(s[i]);
            }
        }
        return st.size()+1;
    }
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int beg=1,end=1e9,ans=0;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(check(points,s,mid)){
                ans=max(ans,mid);
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return check(points,s,ans)-1;
    }
};