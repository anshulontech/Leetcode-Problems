// Approach 1:-

class Solution
{
private:
    int res = 0, negativeSum, currSum = 0;

public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
            totalSum += nums[i];

        negativeSum = totalSum - S;

        if (negativeSum == 0)
            res++;

        if (negativeSum % 2 != 0)
            return 0;
        else
            negativeSum /= 2;

        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            helper(nums, i + 1);
            currSum -= nums[i];
        }

        return res;
    }

    void helper(vector<int> &nums, int index)
    {
        if (currSum > negativeSum)
            return;

        if (currSum == negativeSum)
            res++;

        for (int i = index; i < nums.size(); i++)
        {
            currSum += nums[i];
            helper(nums, i + 1);
            currSum -= nums[i];
        }

        return;
    }
};

// Approach 2:-

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int totalSum = 0;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < S || (S + sum) % 2 != 0 ? 0 : subsetSum(nums, (S + sum) / 2);
    }

    int subsetSum(vector<int> &nums, int sum)
    {
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;

        for (int n : nums)
            for (int i = sum; i >= n; i--)
            {
                dp[i] += dp[i - n];
            }
        return dp[sum];
    }
};