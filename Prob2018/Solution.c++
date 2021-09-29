// Link To Problem:-
// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/

// Solution:-

class Solution
{
public:
    bool placeWordInCrossword(vector<vector<char>> &board, string word)
    {

        int n = board.size(), m = board[0].size(), len = word.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == '#' || (board[i][j] != ' ' && board[i][j] != word[0]))
                    continue;
                else
                {
                    int x = i, y = j, k = 0;
                    if (i == 0 || board[i - 1][y] == '#')
                    {
                        while (x + k < n && k < len && (board[x + k][y] == ' ' || board[x + k][y] == word[k]))
                            k++;

                        if (k == len && (x + k == n || board[x + k][y] == '#'))
                            return true;
                    }

                    if (j == 0 || board[i][j - 1] == '#')
                    {
                        x = i, y = j, k = 0;

                        while (y + k < m && k < len && (board[x][y + k] == ' ' || board[x][y + k] == word[k]))
                            k++;

                        if (k == len && (y + k == m || board[x][y + k] == '#'))
                            return true;
                    }

                    x = i, y = j, k = 0;
                    if (i == n - 1 || board[i + 1][y] == '#')
                    {
                        while (x - k >= 0 && k < len && (board[x - k][y] == ' ' || board[x - k][y] == word[k]))
                            k++;

                        if (k == len && (x - k == -1 || board[x - k][y] == '#'))
                            return true;
                    }

                    if (j == m - 1 || board[i][j + 1] == '#')
                    {
                        x = i, y = j, k = 0;

                        while (y - k >= 0 && k < len && (board[x][y - k] == ' ' || board[x][y - k] == word[k]))
                            k++;

                        if (k == len && (y - k == -1 || board[x][y - k] == '#'))
                            return true;
                    }
                }

        return false;
    }
};