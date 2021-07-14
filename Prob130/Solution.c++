// Link To Problem:-
// https://leetcode.com/problems/surrounded-regions/

// METHOD 1:-

class Solution
{
private:
    int n, m;

public:
    void solve(vector<vector<char>> &board)
    {
        if (board.size() == 0)
            return;
        n = board.size();
        m = board[0].size();

        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < m - 1; j++)
                if (board[i][j] == 'O' && CheckCaptured(board, i, j))
                    makeCaptured(board, i, j);
    }

    bool CheckCaptured(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;

        if (board[i][j] == 'O')
        {
            board[i][j] = 'A';
            bool temp = true;
            temp = temp && CheckCaptured(board, i - 1, j);
            temp = temp && CheckCaptured(board, i, j - 1);
            temp = temp && CheckCaptured(board, i + 1, j);
            temp = temp && CheckCaptured(board, i, j + 1);

            board[i][j] = 'O';

            return temp;
        }

        return true;
    }

    void makeCaptured(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == 'X')
            return;

        board[i][j] = 'X';

        makeCaptured(board, i - 1, j);
        makeCaptured(board, i, j - 1);
        makeCaptured(board, i + 1, j);
        makeCaptured(board, i, j + 1);
    }
};

// METHOD 2:-

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {

        if (board.size() == 0)
            return;

        int N = board.size();
        int M = board[0].size();

        for (int i = 0; i < N; i++)
            if (board[i][0] == 'O')
                dfs(board, i, 0);

        for (int j = 0; j < M; j++)
            if (board[0][j] == 'O')
                dfs(board, 0, j);

        for (int i = 0; i < N; i++)
            if (board[i][M - 1] == 'O')
                dfs(board, i, M - 1);

        for (int j = 0; j < M; j++)
            if (board[N - 1][j] == 'O')
                dfs(board, N - 1, j);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
    }

    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (board[i][j] == 'X' || board[i][j] == 'A')
            return;

        board[i][j] = 'A';

        if (i > 0)
            dfs(board, i - 1, j);
        if (j > 0)
            dfs(board, i, j - 1);
        if (i < board.size() - 1)
            dfs(board, i + 1, j);
        if (j < board[i].size() - 1)
            dfs(board, i, j + 1);
    }
};