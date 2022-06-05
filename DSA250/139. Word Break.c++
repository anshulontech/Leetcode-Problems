// Link To The Problem:-
//  https://leetcode.com/problems/word-break/

// Solution:-

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        unordered_set<string> set;

        for (auto &x : wordDict)
            set.insert(x);

        for (int i = 1; i < n + 1; i++)
        {
            if (dp[i - 1] == false)
                continue;

            for (int j = 1; i + j - 1 <= n; j++)
            {
                string temp = s.substr(i - 1, j);
                if (set.find(temp) != set.end())
                {
                    dp[i - 1 + j] = true;
                }
            }
        }

        return dp[n];
    }
};
