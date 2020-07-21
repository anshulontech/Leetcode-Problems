// Approach 1 :-

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string &word)
    {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (wordFound(board, i, j, word, 0))
                    return true;

        return false;
    }

private:
    bool wordFound(vector<vector<char>> &board, int row, int col, string &word, int index)
    {
        if (index >= word.size() - 1 && board[row][col] == word[index])
            return true;
        if (board[row][col] != word[index])
            return false;
        else
            board[row][col] = '.';

        bool ans = false;

        if (row > 0)
            ans = ans || wordFound(board, row - 1, col, word, index + 1);

        if (col > 0)
            ans = ans || wordFound(board, row, col - 1, word, index + 1);
        if (row < board.size() - 1)
            ans = ans || wordFound(board, row + 1, col, word, index + 1);
        if (col < board[row].size() - 1)
            ans = ans || wordFound(board, row, col + 1, word, index + 1);

        board[row][col] = word[index];

        return ans;
    }
};