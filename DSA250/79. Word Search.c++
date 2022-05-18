// Link To The Problem:-
//  https://leetcode.com/problems/word-search/

// Solution:-

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string &word)
    {
        int n = board.size(), m = board[0].size();

        int k = word.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == word[0])
                {
                    if (dfs(board, i, j, n, m, k, 0, word))
                        return true;
                }

        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, int &n, int &m, int &k, int idx, string &word)
    {
        if (idx >= k)
            return true;

        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[idx])
            return false;

        char c = board[i][j];
        board[i][j] = '#';

        if (dfs(board, i + 1, j, n, m, k, idx + 1, word))
            return true;
        if (dfs(board, i - 1, j, n, m, k, idx + 1, word))
            return true;
        if (dfs(board, i, j + 1, n, m, k, idx + 1, word))
            return true;
        if (dfs(board, i, j - 1, n, m, k, idx + 1, word))
            return true;

        board[i][j] = c;

        return false;
    }
};