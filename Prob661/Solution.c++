// Link To Problem:-
// https://leetcode.com/problems/image-smoother/

// METHOD 1:-

class Solution
{
private:
    int n, m;

public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = n ? grid[0].size() : 0;

        vector<vector<int>> dp(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dp[i][j] = helper(grid, i, j);

        return dp;
    }

    int helper(vector<vector<int>> &grid, int &i, int &j)
    {
        int val = 0, count = 1;

        val += grid[i][j];

        if (i > 0)
        {
            val += grid[i - 1][j];
            count++;

            if (j > 0)
            {
                val += grid[i - 1][j - 1];
                count++;
            }

            if (j < m - 1)
            {
                val += grid[i - 1][j + 1];
                count++;
            }
        }

        if (i < n - 1)
        {
            val += grid[i + 1][j];
            count++;

            if (j > 0)
            {
                val += grid[i + 1][j - 1];
                count++;
            }

            if (j < m - 1)
            {
                val += grid[i + 1][j + 1];
                count++;
            }
        }

        if (j > 0)
        {
            val += grid[i][j - 1];
            count++;
        }
        if (j < m - 1)
        {
            val += grid[i][j + 1];
            count++;
        }

        return val / count;
    }
};