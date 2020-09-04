// Approach 1:-

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int zeroes, ones;

        for (auto &s : strs)
        {
            zeroes = 0, ones = 0;

            for (auto &x : s)
                if (x == '1')
                    ones++;
                else
                    zeroes++;

            for (int i = m; i >= zeroes; i--)
                for (int j = n; j >= ones; j--)
                    dp[i][j] = max(dp[i - zeroes][j - ones] + 1, dp[i][j]);
        }

        return dp[m][n];
    }
};
