// Link To Problem:-
// https://leetcode.com/problems/regular-expression-matching/description/

// Approach 1:-
// Time Complexity:-O(N*M).
// Space Complexity:-O(N*M).

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 0; i < m + 1; i++)
            for (int j = 1; j < n + 1; j++)
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                else
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');

        return dp[m][n];
    }
};

// Approach 2:-
// Time Complexity:-O(N*M).
// Space Complexity:-O(N*2).

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();

        vector<bool> pre(n + 1, false), curr(n + 1, false);

        curr[0] = true;

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
                if (p[j - 1] == '*')
                    curr[j] = curr[j - 2] || (i && pre[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                else
                    curr[j] = i && pre[j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');

            fill(pre.begin(), pre.end(), false);
            swap(pre, curr);
        }

        return pre[n];
    }
};

// Approach 3:-
// Time Complexity:-O(N*M).
// Space Complexity:-O(N).

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();

        vector<bool> curr(n + 1, false);

        for (int i = 0; i < m + 1; i++)
        {

            bool pre = curr[0];
            curr[0] = !i;

            for (int j = 1; j < n + 1; j++)
            {
                bool temp = curr[j];

                if (p[j - 1] == '*')
                    curr[j] = curr[j - 2] || (i && curr[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                else
                    curr[j] = i && pre && (s[i - 1] == p[j - 1] || p[j - 1] == '.');

                pre = temp;
            }
        }

        return curr[n];
    }
};