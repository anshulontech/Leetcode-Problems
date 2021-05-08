// Link To Problem:-
// https://leetcode.com/problems/n-queens/

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board;
        string s;
        for (int i = 0; i < n; i++)
            s.insert(0, ".");
        for (int i = 0; i < n; i++)
            board.push_back(s);
        vector<vector<string>> res;
        assignpoisition(board, 0, n, res);

        return res;
    }

    void assignpoisition(vector<string> &board, int row, int n, vector<vector<string>> &res)
    {
        if (row == n)
        {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++)
            if (checkattack(board, row, i, n))
            {
                board[row][i] = 'Q';
                assignpoisition(board, row + 1, n, res);
                board[row][i] = '.';
            }
    }

    bool checkattack(vector<string> &board, int row, int index, int n)
    {
        // Checking for Column.
        for (int i = 0; i < row; i++)
            if (board[i][index] == 'Q')
                return false;

        // Checking for 45` angle.
        for (int i = row - 1, j = index - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // Checking for 135` angle.
        for (int i = row - 1, j = index + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;
        return true;
    }
};