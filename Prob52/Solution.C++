// Link To Problem:-
// https://leetcode.com/problems/n-queens-ii/description/

class Solution
{
private:
    int res = 0;
    int N;

public:
    int totalNQueens(int n)
    {
        vector<vector<char>> store(n, vector<char>(n));
        N = n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                store[i][j] = '.';

        backTrack(store, n, 0);

        return res;
    }

    void backTrack(vector<vector<char>> &store, int &n, int row)
    {
        if (n == 0)
        {
            res++;
            return;
        }

        if (row == N)
            return;

        n--;

        for (int i = row; i < N; i++)
            for (int j = 0; j < N; j++)
                if (valid(store, i, j))
                {
                    store[i][j] = 'Q';
                    backTrack(store, n, i + 1);
                    store[i][j] = '.';
                }

        n++;
    }

    bool valid(vector<vector<char>> &store, int row, int col)
    {

        for (int i = row - 1; i >= 0; i--)
            if (store[i][col] == 'Q')
                return false;

        for (int j = col - 1; j >= 0; j--)
            if (store[row][j] == 'Q')
                return false;

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (store[i][j] == 'Q')
                return false;

        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
            if (store[i][j] == 'Q')
                return false;

        return true;
    }
};