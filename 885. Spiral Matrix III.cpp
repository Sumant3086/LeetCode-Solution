// 885. Spiral Matrix III
// Solved
// Medium
// Topics
// Companies
// You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

// You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

// Return an array of coordinates representing the positions of the grid in the order you visited them.

 

// Example 1:


// Input: rows = 1, cols = 4, rStart = 0, cStart = 0
// Output: [[0,0],[0,1],[0,2],[0,3]]
// Example 2:


// Input: rows = 5, cols = 6, rStart = 1, cStart = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
 

// Constraints:

// 1 <= rows, cols <= 100
// 0 <= rStart < rows
// 0 <= cStart < cols

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int count=rows*cols-1;
        pair<int,int> currIndex=make_pair(rStart,cStart);
        int right=1,down=1,left=2,up=2;
        vector<vector<int>> ans;
        vector<int> tempo;
        tempo.push_back(rStart);
        tempo.push_back(cStart);
        ans.push_back(tempo);
        while(count>0)
        {
            int currRight=right;
            while(currRight>0)
            {
                currIndex=make_pair(currIndex.first,currIndex.second+1);
                currRight--;
                if(currIndex.first<rows && currIndex.second<cols && currIndex.first>=0 && currIndex.second>=0)
                {
                    count--;
                    vector<int> temp;
                    ans.push_back({currIndex.first,currIndex.second});
                }
            }
            right+=2;
            int currDown=down;
            while(currDown>0)
            {
                currIndex=make_pair(currIndex.first+1,currIndex.second);
                currDown--;
                if(currIndex.first<rows && currIndex.second<cols && currIndex.first>=0 && currIndex.second>=0)
                {
                    count--;
                    ans.push_back({currIndex.first,currIndex.second});
                }
            }
            down+=2;
            int currleft=left;
            while(currleft>0)
            {
                currIndex=make_pair(currIndex.first,currIndex.second-1);
                currleft--;
                if(currIndex.first<rows && currIndex.second<cols && currIndex.first>=0 && currIndex.second>=0)
                {
                    count--;
                    ans.push_back({currIndex.first,currIndex.second});
                }
            }
            left+=2;
            int currUp=up;
            while(currUp>0)
            {
                currIndex=make_pair(currIndex.first-1,currIndex.second);
                currUp--;
                if(currIndex.first<rows && currIndex.second<cols && currIndex.first>=0 && currIndex.second>=0)
                {
                    count--;
                    ans.push_back({currIndex.first,currIndex.second});
                }
            }
            up+=2;
        }
        return ans;
        
    }
};