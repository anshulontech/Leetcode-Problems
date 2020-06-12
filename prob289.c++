// https://leetcode.com/problems/game-of-life/

// Time Complexity:-O(N^2).
// Space Complexity:-O(1).
    
// Approach:-
//     In this we will check for each cell that how many live neighbour cells are their for each cell and on based on 
// condition we will change their values. For dead to live we will initially assign 2 so that we have a idea that in 
// current state the cell is dead and similarely for the 1 to 0 we will assign -1 as it indicates that this was earlier 
// living buy in next generation it will die amd so on we will do for all the cells . After this we will again traverse 
// the matrix to change them again.

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == 0)
                {
                    if (checkLive(board, i, j) == 3)
                        board[i][j] = 2;
                }
                else
                {
                    int val = checkLive(board, i, j);

                    if (val < 2 || val > 3)
                        board[i][j] = -1;
                }

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == 2)
                    board[i][j] = 1;
                else
                {
                    if (board[i][j] == -1)
                        board[i][j] = 0;
                }

        return;
    }

    int checkLive(vector<vector<int>> &board, int i, int j)
    {
        int val = 0;

        if (i > 0)
        {
            if (abs(board[i - 1][j]) == 1)
                val++;
            if (j > 0)
                if (abs(board[i - 1][j - 1]) == 1)
                    val++;
            if (j < board[0].size() - 1)
                if (abs(board[i - 1][j + 1]) == 1)
                    val++;
        }

        if (i < board.size() - 1)
        {
            if (abs(board[i + 1][j]) == 1)
                val++;
            if (j > 0)
                if (abs(board[i + 1][j - 1]) == 1)
                    val++;
            if (j < board[0].size() - 1)
                if (abs(board[i + 1][j + 1]) == 1)
                    val++;
        }

        if (j > 0)
            if (abs(board[i][j - 1]) == 1)
                val++;
        if (j < board[0].size() - 1)
            if (abs(board[i][j + 1]) == 1)
                val++;

        return val;
    }
};