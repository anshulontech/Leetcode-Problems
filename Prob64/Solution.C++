// Link To Problem:-
// https://leetcode.com/problems/minimum-path-sum/submissions/

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int x = grid.size();
        int y = grid[0].size();
        vector<int> store(x, grid[0][0]);
        for (int i = 1; i < x; i++)
            store[i] = store[i - 1] + grid[i][0]; // Upadting the store by cheking how values change if we will move vertically.

        for (int j = 1; j < y; j++)
        {
            store[0] += grid[0][j];
            for (int i = 1; i < x; i++)
                store[i] = min(store[i - 1], store[i]) + grid[i][j]; //updating the values by checking minimum change on movement either from up or from left.
        }

        return store[x - 1]; // returning the value which represents the last grid on mimimum change.
    }
};

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int x = grid.size();
        int y = grid[0].size();
        vector<int> store(y, grid[0][0]);
        for (int i = 1; i < y; i++)
            store[i] = store[i - 1] + grid[0][i]; // Upadting the store by cheking how values change if we will move horizontally.

        for (int i = 1; i < x; i++)
        {
            store[0] += grid[i][0];
            for (int j = 1; j < y; j++)
                store[j] = min(store[j - 1], store[j]) + grid[i][j]; //updating the values by checking minimum change on movement either from up or from left.
        }

        return store[y - 1]; // returning the value which represents the last grid on mimimum change.
    }
};