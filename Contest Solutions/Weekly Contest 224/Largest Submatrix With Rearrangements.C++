// Solution:-

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int j = n - 1; j >= 0; j--)
            if (matrix[m - 1][j] == 1)
                dp[m - 1][j] = 1;

        for (int i = m - 2; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                if (matrix[i][j] == 0)
                    continue;
                else
                    dp[i][j] = dp[i + 1][j] + 1;

        int res = 0;

        for (auto &x : dp)
        {
            sort(x.begin(), x.end());

            for (int i = 0; i < n; i++)
                res = max(res, x[i] * (n - i));
        }

        return res;
    }
};