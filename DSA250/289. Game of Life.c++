// Link To The Problem:-
//  https://leetcode.com/problems/game-of-life/

// Solution:-

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int count = 0;

                if ((i - 1 >= 0) && (board[i - 1][j] == 1 || board[i - 1][j] == 2))
                    count++;
                if ((i + 1 < n) && (board[i + 1][j] == 1 || board[i + 1][j] == 2))
                    count++;
                if ((j - 1 >= 0) && (board[i][j - 1] == 1 || board[i][j - 1] == 2))
                    count++;
                if ((j + 1 < m) && (board[i][j + 1] == 1 || board[i][j + 1] == 2))
                    count++;

                if ((i - 1 >= 0 && j - 1 >= 0) && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 2))
                    count++;
                if ((i + 1 < n && j - 1 >= 0) && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 2))
                    count++;

                if ((i - 1 >= 0 && j + 1 < m) && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 2))
                    count++;
                if ((i + 1 < n && j + 1 < m) && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 2))
                    count++;

                if (board[i][j] == 1 && count < 2)
                    board[i][j] = 2;
                else if (board[i][j] == 1 && count > 3)
                    board[i][j] = 2;
                else if (board[i][j] == 0 && count == 3)
                    board[i][j] = 3;
            }

        for (auto &x : board)
            for (auto &y : x)
                y %= 2;
    }
};