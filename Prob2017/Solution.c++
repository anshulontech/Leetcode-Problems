// Link To Problem:-
// https://leetcode.com/problems/grid-game/

// Solution:-

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        int n = grid[0].size();
        if (n == 1)
            return 0;

        // if(n==2) return min(grid[0][1],grid[1][0]);

        vector<long long> fSum(n), sSum(n);

        fSum[n - 1] = grid[0][n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            fSum[i] = fSum[i + 1] + grid[0][i];
        }

        sSum[0] = grid[1][0];
        for (int i = 1; i < n; i++)
            sSum[i] = sSum[i - 1] + grid[1][i];

        long long res = min(fSum[1], sSum[n - 2]);

        for (int i = 1; i < n - 1; i++)
        {
            res = min(res, max(fSum[i + 1], sSum[i - 1]));
        }

        return res;
    }
};