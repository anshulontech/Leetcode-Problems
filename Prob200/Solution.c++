// Link To Problem:-
// https://leetcode.com/problems/number-of-islands/

// METHOD 1:-

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == '1')
                {
                    count++;
                    remove_island(grid, i, j);
                }
        return count;
    }

    void remove_island(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '0';

        if (i > 0 && grid[i - 1][j] == '1')
            remove_island(grid, i - 1, j);
        if (j > 0 && grid[i][j - 1] == '1')
            remove_island(grid, i, j - 1);
        if (i < grid.size() - 1 && grid[i + 1][j] == '1')
            remove_island(grid, i + 1, j);
        if (j < grid[i].size() - 1 && grid[i][j + 1] == '1')
            remove_island(grid, i, j + 1);
    }
};