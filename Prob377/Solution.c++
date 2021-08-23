// Link To Problem:-
// https://leetcode.com/problems/combination-sum-iv/

// METHOD 1:-

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned int> dp(target + 1, 0);

        sort(nums.begin(), nums.end());

        dp[0] = 1;

        for (int i = 0; i < target + 1; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] > i)
                    break;
                else
                    dp[i] += dp[i - nums[j]];
            }
        }

        return dp[target];
    }
};

// METHOD 2:-

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned int> dp(target + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < target + 1; i++)
            for (int j = 0; j < nums.size(); j++)
                if (nums[j] <= i)
                    dp[i] += dp[i - nums[j]];

        return dp[target];
    }
};

// METHOD 3:-

class Solution
{
private:
    vector<unsigned int> dp;

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        for (int i = 0; i < target + 1; i++)
            dp.push_back(-1);

        dp[0] = 1;

        return helper(nums, target);
    }

    int helper(vector<int> &nums, int target)
    {
        if (dp[target] != -1)
            return dp[target];

        int res = 0;
        for (int i = 0; i < nums.size(); i++)
            if (target >= nums[i])
                res += helper(nums, target - nums[i]);

        dp[target] = res;

        return res;
    }
};