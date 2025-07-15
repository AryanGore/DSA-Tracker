//problem statement.

// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

// Example 1:
// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// Explanation:
// In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
  
// Example 2:
// Input: board = [["X"]]
// Output: [["X"]]


// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.

// Code Solution : 

class Solution {
public:
    void dfs(int x , int y , vector<vector<char>>& board ,vector<vector<bool>>&visited){
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y] == 'X'){
            return;
        }
        visited[x][y] = true;
        vector<int> dir = { 0 , 1 , 0 , -1 , 0 };
        for(int i = 0 ; i < 4 ; ++i){
            int nx = x + dir[i];
            int ny = y + dir[i+1];
             if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visited[nx][ny] && board[nx][ny] == 'O') {
                dfs(nx, ny, board, visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>>visited(board.size() , vector<bool>(board[0].size() , false));
        for(int i= 0 ; i<board.size() ; ++i){ //left column traversal.
            if(board[i][0] == 'O'){
                dfs(i,0,board,visited);
            }
        }
        for(int i=0 ; i<board.size() ; ++i){ //right column traversal.
            if(board[i][board[0].size()-1]){
                dfs(i,board[0].size()-1,board,visited);
            }
        }
        for(int i= 0 ; i<board[0].size() ; ++i){ //top row traversal.
            if(board[0][i] == 'O'){
                dfs(0,i,board,visited);
            }
        }
        for(int i=0 ; i<board[0].size() ; ++i){ //bottom row traversal.
            if(board[board.size()-1][i]){
                dfs(board.size()-1,i,board,visited);
            }
        }
        for(int i = 0 ; i < board.size() ; ++i){
            for(int j = 0 ; j < board[0].size() ; ++j){
                if(board[i][j] == 'O' && visited[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }

    }
};

// solution explanation : 
// In this code the approach we are following is iterating over the edges of the  matrix (board)we check the particular index in theboard matrix edges if its 'O' we mark it as 
//visited in visited matrix we created explicitly , then we do this for all the edges, once all these O's are marked , we again iterate over the matrix and check for O's and also checlk if 
//they are visite or not , if they are visted then we dont mark them by 'X' but if they are not we mark them by X. this solution takes O{m*n) time to complete and takes O(n} space for
// visited boolean matrix to store

