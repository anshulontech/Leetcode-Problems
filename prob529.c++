// https://leetcode.com/problems/minesweeper/

// Time Complexity:-O(N^2)-- Worst.
// Space Complexity:-O(N^2) -- Worst for recurssion stack else O(1).
    
// Approach:-
//     Check for the given poisition and if mine was found than return answer as described else check number of mines 
// near to it, If it is zero and assign it with B and do the same for all 8 adjacent poisition else if number of mines 
// will be greater than 0 than assign that poisition with number of mines and return from there without doing any further 
// activity.

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i=click[0],j=click[1];
        
        if(board[i][j]=='M') {
            board[i][j]='X';
            return board;
        }
        else
            makeBoard(board,i,j);
        
        return board;
    }
    
    void makeBoard(vector<vector<char>>& board,int i,int j) {
        if(board[i][j]!='E')
            return ;
        int val=0;
        if(i>0 ) {
            if(board[i-1][j]=='M')
                val++;
            if(j>0 && board[i-1][j-1]=='M')
                val++;
            if(j<board[i].size()-1 && board[i-1][j+1]=='M')
                val++;
        }
        
        if(i<board.size()-1) {
            if(board[i+1][j]=='M')
                val++;
            if(j>0 && board[i+1][j-1]=='M')
                val++;
            if(j<board[i].size()-1 && board[i+1][j+1]=='M')
                val++;
        }
        if(j>0 && board[i][j-1]=='M')
            val++;
        if(j<board[i].size()-1 && board[i][j+1]=='M')
            val++;
        
        if(val>0) 
            board[i][j]='0'+val;
        else {
            board[i][j]='B';
            if(i>0) {
                makeBoard(board,i-1,j);
                if(j>0)
                    makeBoard(board,i-1,j-1);
                if(j<board[i].size()-1)
                    makeBoard(board,i-1,j+1);
            }
            if(i<board.size()-1) {
                makeBoard(board,i+1,j);
                if(j>0)
                    makeBoard(board,i+1,j-1);
                if(j<board[i].size()-1)
                    makeBoard(board,i+1,j+1);
            }
            
            if(j>0)
                makeBoard(board,i,j-1);
            if(j<board[i].size()-1)
                makeBoard(board,i,j+1);
            
        }
        
        return ;
    }
};