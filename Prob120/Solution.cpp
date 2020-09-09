// Approach 1:-

class Solution
{
private:
    int res = 0;

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        res += triangle[0][0];

        res += helper(triangle, 1, 0);

        return res;
    }

    int helper(vector<vector<int>> &triangle, int row, int index)
    {
        if (row >= triangle.size())
            return 0;

        int first = triangle[row][index] + helper(triangle, row + 1, index);
        int second = triangle[row][index + 1] + helper(triangle, row + 1, index + 1);

        return min(first, second);
    }
};

// Approach 2:-

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];

        return dp[0];
    }
};