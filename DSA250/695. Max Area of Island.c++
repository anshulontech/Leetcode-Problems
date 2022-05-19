// Link To The Problem:-
//  https://leetcode.com/problems/max-area-of-island/

// Solution:-

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        int res = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 0)
                    continue;
                else
                {
                    int count = 1;
                    res = max(res, count);

                    grid[i][j] = 0;

                    dfs(grid, i + 1, j, n, m, count, res);
                    dfs(grid, i - 1, j, n, m, count, res);
                    dfs(grid, i, j - 1, n, m, count, res);
                    dfs(grid, i, j + 1, n, m, count, res);
                }

        return res;
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int &n, int &m, int &count, int &res)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return;

        count++;
        grid[i][j] = 0;

        res = max(res, count);

        dfs(grid, i + 1, j, n, m, count, res);
        dfs(grid, i - 1, j, n, m, count, res);
        dfs(grid, i, j - 1, n, m, count, res);
        dfs(grid, i, j + 1, n, m, count, res);
    }
};