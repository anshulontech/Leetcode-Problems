// https://leetcode.com/problems/valid-tic-tac-toe-state/description/

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int countX=0,countO=0;
        
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                if(board[i][j]=='X')
                    countX++;
                else
                    if(board[i][j]=='O')
                        countO++;
        
        cout<<countX<<" "<<countO<<endl;
        
        if(!(countX==countO || countX==countO+1))
            return false;
        else
            if(countX==countO)
                return !isWin(board,'X');
            else
                return !isWin(board,'O');
        
    }
    
    bool isWin(vector<string>& board, char c) {
        for(int i=0;i<3;i++) {
            if(board[i][0]==c && board[i][0]==board[i][1] && board[i][1]==board[i][2])
                return true;
            
            if(board[0][i]==c && board[0][i]==board[1][i] && board[1][i]==board[2][i])
                return true;
            
        }
            
        if(board[0][0]==c && board[1][1]==board[0][0] && board[1][1]==board[2][2])
            return true;
        
        if(board[0][2]==c && board[1][1]==board[0][2] && board[1][1]==board[2][0])
            return true;
        
        return false;
    }
    
};