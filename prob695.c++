// https://leetcode.com/problems/max-area-of-island/description/

// Time Complexity : -O(N ^ 2).
// Space Complexity : -O(N ^ 2).For frecurssion stack.

// Approach : -For each land we will check the number of adjacent lands using DFS and make them water as they are 
// visited and than check that is the current area is greater than previous one or not .If it is than we will upadte 
// the max area and finally return that one.

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int res = 0;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1)
                    res = max(res, findArea(grid, i, j));

        return res;
    }

    int findArea(vector<vector<int>> &grid, int i, int j)
    {
        int count = 1;
        grid[i][j] = 0;

        if (i > 0 && grid[i - 1][j] == 1)
            count += findArea(grid, i - 1, j);

        if (i < grid.size() - 1 && grid[i + 1][j] == 1)
            count += findArea(grid, i + 1, j);

        if (j > 0 && grid[i][j - 1] == 1)
            count += findArea(grid, i, j - 1);

        if (j < grid[i].size() - 1 && grid[i][j + 1] == 1)
            count += findArea(grid, i, j + 1);

        return count;
    }
};