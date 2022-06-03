// Link To The Problem:-
//  https://leetcode.com/problems/divisor-game/

// Solution:-

class Solution
{
public:
    bool divisorGame(int n)
    {
        vector<bool> dp(n + 1, false);

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i && !dp[i]; j++)
            {
                if (i % j == 0 && dp[i - j] == false)
                    dp[i] = true;
            }
        }

        return dp[n];
    }
};

// Solution 2:-

class Solution
{
public:
    bool divisorGame(int n)
    {
        return n % 2 == 0;
    }
};
