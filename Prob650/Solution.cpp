// Approach 1:-

class Solution
{
public:
    int minSteps(int n)
    {
        vector<int> dp(n + 1);

        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = i;
            for (int j = i - 1; j > 1; j--)
            {
                if (i % j == 0)
                {
                    dp[i] = dp[j] + (i / j);
                    break;
                }
            }
        }

        return dp[n];
    }
};

// Approach 2:-

class Solution
{
public:
    int minSteps(int n)
    {

        static vector<int> dp(2, 0);

        while (dp.size() < n + 1)
        {
            int n = dp.size();

            dp.push_back(n);

            for (int i = n - 1; i > 0; i--)
                if (n % i == 0)
                {
                    dp[n] = n / i + dp[i];
                    break;
                }
        }

        return dp[n];
    }
};

// Approach 3:-

class Solution
{
public:
    int minSteps(int n)
    {

        for (int i = n - 1; i > 0; i--)
            if (n % i == 0)
                return minSteps(i) + n / i;

        return n - 1;
    }
};