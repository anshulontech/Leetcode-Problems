// Link To Problem:-
// https://leetcode.com/problems/dungeon-game/

// Tine Complexity:-O(N*M).
// Space Complexity:-O(N*M).

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int n = dungeon.size();
        int m = n ? dungeon[0].size() : 0;

        vector<vector<int>> dp(n, vector<int>(m));

        dp[n - 1][m - 1] = dungeon[n - 1][m - 1] > 0 ? 0 : dungeon[n - 1][m - 1];

        for (int i = n - 2; i >= 0; i--)
            dp[i][m - 1] = (dp[i + 1][m - 1] + dungeon[i][m - 1]) > 0 ? 0 : (dp[i + 1][m - 1] + dungeon[i][m - 1]);

        for (int j = m - 2; j >= 0; j--)
            dp[n - 1][j] = (dp[n - 1][j + 1] + dungeon[n - 1][j]) > 0 ? 0 : (dp[n - 1][j + 1] + dungeon[n - 1][j]);

        for (int i = n - 2; i >= 0; i--)
            for (int j = m - 2; j >= 0; j--)
            {
                int val = max(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = (val + dungeon[i][j]) > 0 ? 0 : (val + dungeon[i][j]);
            }

        return abs(dp[0][0]) + 1;
    }
};