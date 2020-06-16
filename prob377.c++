// https://leetcode.com/problems/combination-sum-iv/

// Time Complexity:-O(N*Log(N)+(target+1)*N).
// Space Complexity:-O(target+1).

// Approach:-
//     In this what we are going to do iss that we will use bottom - up approach. Hence we will first check that how 
// many ways are there to calculate the sum 0 than for 1 than for 2 and so on till target, Now here we are making a 
// dp array which will help us to remember that for particular target how many ways are there and hence we will use 
// this for help s that we have no need to calculate the sum of certain targets which were already discovered.

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

// Time Complexity:-O((target+1)*N).
// Space Complexity:-O(target+1).

// Approach:-
//     Same As that of above but here we are not using sorting here we will traverse the whole array taret +1 times but 
// there if the value goes higher than current target than we can break the loop.

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

// Approach:-
//     This is Top-Down Approach for this problem.

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