// Approach 1:-

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> store;
        int n = s.size();

        for (auto x : wordDict)
            store.insert(x);

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
            {
                string temp = s.substr(j, i - j);
                if (dp[j] && store.find(temp) != store.end())
                {
                    dp[i] = true;
                    break;
                }
            }

        return dp[n];
    }
};