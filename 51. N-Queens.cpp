// 51. N-Queens
// Solved
// Hard
// Topics
// Companies
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9

// class Solution {
// public:
//     vector<vector<string>>sols; // 2D vector of strings to store the solutions
//     vector<vector<string>>solveNQueens(int n){    
// 	    vector<string>board(n,string(n,'.'));  // creating an empty board
// 	    solve(board,0); // calling the recursive function
// 	    return sols; 
//     }
//     bool isSafe(vector<string>& board,int row,int col){
// 	    int n=size(board);
// 	    for(int i=0;i<n;i++){
// 			// checking if there is a queen in the same column
// 		    if(board[i][col]=='Q')return false; 
// 		    // checking if there is a queen in the same diagonal (left to right)
// 		    if(row-i>=0 && col-i>=0 && board[row-i][col-i]=='Q')return false;
// 		    if(row-i>=0 && col+i<n && board[row-i][col+i]=='Q')return false;
// 		    // No need to traverse more since the lower rows below current row attribute will always be safe.
// 			/* if(row + i <  n && col - i >= 0 && board[row + i][col - i] == 'Q') return false;
// 			if(row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') return false; */
// 	    }
// 	    return true;
//     }
//     // Recursive Function (solve) - It basically tries all possible placement of queen for the current row & recurses for it's next row
//     void solve(vector<string>&board,int row){
// 	// Base condition. 
//     // We reached the last row, so we have a solution so we add it to the solution vector
// 	    if(row==size(board)){ 
// 		    sols.push_back(board);
// 		    return;
//     	}            
// 	    // Try placing a queen on each column for a given row. 
//         // Explore next row by placing Q at each valid column for the current row
// 	    for(int col=0;col<size(board);col++){
// 		    if(isSafe(board,row,col)){
// 			    board[row][col]='Q';    // Queen placed on a valid cell
// 			    solve(board,row+1);    // Exploring next row
// 			    board[row][col]='.';    // Backtracking to get all possible solutions
// 		    }
//         }
//     }
// };

class Solution {
public:
    void solve(int col,vector<string>&vc,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&upperdiag,vector<int>&lowerdiag,int n){
        if(col==n){
            ans.push_back(vc);
            return ;
        }
        for(int i=0;i<n;i++){
            if(leftrow[i]==0 and upperdiag[(n-1)+col-i]==0 and lowerdiag[i+col]==0){
                vc[i][col]='Q';
                leftrow[i]=1;
                upperdiag[(n-1)+col-i]=1;
                lowerdiag[i+col]=1;
                solve(col+1,vc,ans,leftrow,upperdiag,lowerdiag,n);
                vc[i][col]='.';
                leftrow[i]=0;
                upperdiag[(n-1)+col-i]=0;
                lowerdiag[i+col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>vc(n);
        string st(n,'.');
        for(int i=0;i<n;i++)
            vc[i]=st;
        vector<int>leftrow(n,0),upperdiag(2*n-1,0),lowerdiag(2*n-1,0);
        solve(0,vc,ans,leftrow,upperdiag,lowerdiag,n);
        return ans;
    }
};