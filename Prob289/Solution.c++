// Link To The Problem:-
// https://leetcode.com/problems/game-of-life/

// Solution:-

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int score = 0;

                if (i - 1 >= 0 && (board[i - 1][j] == 1 || board[i - 1][j] == -1))
                    score++;
                if (i + 1 < n && (board[i + 1][j] == 1 || board[i + 1][j] == -1))
                    score++;
                if (j - 1 >= 0 && (board[i][j - 1] == 1 || board[i][j - 1] == -1))
                    score++;
                if (j + 1 < m && (board[i][j + 1] == 1 || board[i][j + 1] == -1))
                    score++;
                if (i - 1 >= 0 && j - 1 >= 0 && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == -1))
                    score++;
                if (i + 1 < n && j - 1 >= 0 && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == -1))
                    score++;
                if (i - 1 >= 0 && j + 1 < m && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == -1))
                    score++;
                if (i + 1 < n && j + 1 < m && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == -1))
                    score++;

                if (board[i][j] == 0)
                {
                    if (score == 3)
                        board[i][j] = 2;
                }
                else
                {
                    if (score < 2 || score > 3)
                        board[i][j] = -1;
                }
                // cout<<board[i][j];
            }
            // cout<<endl;
        }
        // cout<<endl;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 2)
                    board[i][j] = 1;
                else if (board[i][j] == -1)
                    board[i][j] = 0;
    }
};