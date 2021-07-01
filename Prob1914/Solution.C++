// Link To Problem:-
// https://leetcode.com/problems/cyclically-rotating-a-grid/

// METHOD 1:-

class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        int layers = min(m, n) / 2;

        for (int lCount = 0; lCount < layers; lCount++)
        {
            vector<int> temp;

            for (int i = lCount; i < m - lCount; i++)
                temp.push_back(grid[lCount][i]);

            for (int i = lCount + 1; i < n - lCount; i++)
                temp.push_back(grid[i][m - 1 - lCount]);

            for (int i = m - 1 - lCount - 1; i >= lCount; i--)
                temp.push_back(grid[n - lCount - 1][i]);

            for (int i = n - lCount - 2; i > lCount; i--)
                temp.push_back(grid[i][lCount]);

            int poi = k, size = temp.size();

            for (int i = lCount; i < m - lCount; i++, poi++)
                grid[lCount][i] = temp[poi % size];

            for (int i = lCount + 1; i < n - lCount; i++, poi++)
                grid[i][m - 1 - lCount] = temp[poi % size];

            for (int i = m - 1 - lCount - 1; i >= lCount; i--, poi++)
                grid[n - lCount - 1][i] = temp[poi % size];

            for (int i = n - lCount - 2; i > lCount; i--, poi++)
                grid[i][lCount] = temp[poi % size];
        }

        return grid;
    }
};