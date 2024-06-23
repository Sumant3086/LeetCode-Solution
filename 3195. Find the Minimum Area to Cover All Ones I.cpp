// 3195. Find the Minimum Area to Cover All Ones I
// Solved
// Medium
// Companies
// Hint
// You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

// Return the minimum possible area of the rectangle.

 

// Example 1:

// Input: grid = [[0,1,0],[1,0,1]]

// Output: 6

// Explanation:



// The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.

// Example 2:

// Input: grid = [[0,0],[1,0]]

// Output: 1

// Explanation:



// The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

 

// Constraints:

// 1 <= grid.length, grid[i].length <= 1000
// grid[i][j] is either 0 or 1.
// The input is generated such that there is at least one 1 in grid.

// class Solution {
// public:
//     int minimumArea(vector<vector<int>>& grid) {
//                 int minRow=numeric_limits<int>::max();
//         int maxRow=numeric_limits<int>::min();
//         int minCol=numeric_limits<int>::max();
//         int maxCol=numeric_limits<int>::min();
//         int rows=grid.size();
//         int cols=grid[0].size();
        
//         for(int i=0;i<rows;++i){
//             for(int j=0;j<cols;++j){
//                 if(grid[i][j]==1){
//                     if(i<minRow)minRow=i;
//                     if(i>maxRow)maxRow=i;
//                     if(j<minCol)minCol=j;
//                     if(j>maxCol)maxCol=j;
//                 }
//             }
//         }
        
//         int height=maxRow-minRow+1;
//         int width=maxCol-minCol+1;
//         int area=height*width;
//         return area;
//     }
// };


class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
            
        int x1=INT_MAX,x2=INT_MIN,y1=INT_MAX,y2=INT_MIN; 
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    x1=min(x1,i);
                    x2=max(x2,i);
                    y1=min(y1,j);
                    y2=max(y2,j);
                }
            }
        }
        
        if(x1==INT_MAX) return 0;
        
        return (x2-x1+1)*(y2-y1+1);
    }
};