// Link To Problem:-
// https://leetcode.com/problems/longest-palindromic-subsequence/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N^2).

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i < n - l + 1; i++)
            {
                int j = i + l - 1;
                if (s[i] == s[j])
                    if (l == 2)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};