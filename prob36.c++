// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                if(board[i][j]!='.')
                {
                    int k=i+1;
                    while(k<board.size())
                    {
                        if(board[k][j]==board[i][j])
                            return false;
                        
                        k++;
                    }
                    k=j+1;
                    while(k<board[i].size())
                    {
                        if(board[i][k]==board[i][j])
                            return false;
                        
                        k++;
                    }
                    
                    for(int x=0;x<3;x++)
                        for(int y=0;y<3;y++)
                        {
                            if((i!=(x+(i/3)*3)||j!=(y+(j/3)*3))&&board[i][j]==board[x+(i/3)*3][y+(j/3)*3])
                                return false;
                        }
                }
        
        
        return true;
    }
};