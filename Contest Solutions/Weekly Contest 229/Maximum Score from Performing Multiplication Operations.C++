// Solution:-

class Solution
{
public:
    int maximumScore(vector<int> &N, vector<int> &M)
    {
        memset(dp, -1, sizeof dp);
        return helper(N, M, 0, 0);
    }

private:
    int dp[1001][1001];

    int helper(vector<int> &N, vector<int> &M, int n, int s)
    {
        if (n == M.size())
            return 0;
        if (dp[n][s] != -1)
            return dp[n][s];

        int res1 = helper(N, M, n + 1, s + 1) + M[n] * N[s];
        int res2 = helper(N, M, n + 1, s) + M[n] * N[N.size() - (n - s) - 1];

        return dp[n][s] = max(res1, res2);
    }
};