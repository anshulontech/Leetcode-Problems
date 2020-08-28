// Approach 1:-

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days[days.size() - 1];
        vector<int> dp(n + 1, 0);

        for (int i = 0, j = 1; j < n + 1; j++, i++)
        {
            while (j < n + 1 && days[i] != j)
            {
                dp[j] = dp[j - 1];
                j++;
            }

            int one = dp[j - 1] + costs[0];
            int seven = dp[max(j - 7, 0)] + costs[1];
            int thirty = dp[max(j - 30, 0)] + costs[2];

            dp[j] = min(one, min(seven, thirty));
        }

        return dp[n];
    }
};