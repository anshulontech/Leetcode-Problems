// Link To The Problem:-
//  https://leetcode.com/problems/jump-game-ii/

// Solution 1:-

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= nums[i] && i + j < n; j++)
                dp[i + j] = min(dp[i + j], dp[i] + 1);
        }

        return dp[n - 1];
    }
};

// Solution 2:-

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int end = 0, start = 0, res = 0, n = nums.size();

        while (end < n - 1)
        {
            res++;
            int maxEnd = end;
            for (int i = start; i <= end; i++)
                if (i + nums[i] >= n - 1)
                    return res;
                else
                    maxEnd = max(maxEnd, i + nums[i]);

            start = end + 1;
            end = maxEnd;
        }

        return res;
    }
};