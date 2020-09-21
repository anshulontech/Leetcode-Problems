// Approach 1:-

class Solution
{
private int totNonObs = 0, res = 0, m, n;
private Pair<Integer, Integer> start;
public int uniquePathsIII(int[][] grid)
    {
        n = grid.length;
        m = grid[0].length;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 0)
                    totNonObs++;
                else if (grid[i][j] == 1)
                    start = new Pair(i, j);

        int currNonObs = 0;

        helper(grid, start.getKey(), start.getValue(), currNonObs);

        return res;
    }

private void helper(int[][] grid, int i, int j, int currNonObs)
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
}