// Approach 1:-

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int totalSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            totalSum += nums[i];

        if (totalSum % 2 != 0)
            return false;

        int halfSum = totalSum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(halfSum + 1, false));

        for (int i = 0; i < n + 1; i++)
            dp[i][0] = true;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < halfSum + 1; j++)
                dp[i][j] = dp[i - 1][j] || (j >= nums[i - 1] ? (dp[i - 1][j - nums[i - 1]]) : false);

            if (dp[i][halfSum])
                return true;
        }
        return false;
    }
};

// Approach 2:-

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int totalSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            totalSum += nums[i];

        if (totalSum % 2 != 0)
            return false;

        int halfSum = totalSum / 2;
        vector<bool> dp(halfSum + 1, false);

        dp[0] = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = halfSum; j >= nums[i]; j--)
                dp[j] = dp[j] || dp[j - nums[i]];

            if (dp[halfSum])
                return true;
        }

        return false;
    }
};