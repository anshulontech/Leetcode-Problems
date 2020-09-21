// Approach 1:-

class Solution
{
private:
    int totNonObs = 0, res = 0, m, n;
    pair<int, int> start;

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 0)
                    totNonObs++;
                else if (grid[i][j] == 1)
                    start = {i, j};

        int currNonObs = 0;

        helper(grid, start.first, start.second, currNonObs);

        return res;
    }

    void helper(vector<vector<int>> &grid, int i, int j, int &currNonObs)
    {
        if (grid[i][j] == 2)
        {
            if (totNonObs == currNonObs)
                res++;

            return;
        }
        int val = grid[i][j];

        grid[i][j] = -2;

        if (val == 0)
            currNonObs++;

        if (i - 1 >= 0 && grid[i - 1][j] != 1 && grid[i - 1][j] != -1 && grid[i - 1][j] != -2)
            helper(grid, i - 1, j, currNonObs);
        if (i + 1 < n && grid[i + 1][j] != 1 && grid[i + 1][j] != -1 && grid[i + 1][j] != -2)
            helper(grid, i + 1, j, currNonObs);
        if (j - 1 >= 0 && grid[i][j - 1] != 1 && grid[i][j - 1] != -1 && grid[i][j - 1] != -2)
            helper(grid, i, j - 1, currNonObs);
        if (j + 1 < m && grid[i][j + 1] != 1 && grid[i][j + 1] != -1 && grid[i][j + 1] != -2)
            helper(grid, i, j + 1, currNonObs);

        grid[i][j] = val;

        if (val == 0)
            currNonObs--;
    }
};
