// Link To Problem:-
// https://leetcode.com/problems/plates-between-candles/

// Solution:-

class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        int n = s.size();

        vector<int> count(n), prev(n), next(n);

        if (s[0] == '|')
            prev[0] = 0;
        else
            prev[0] = -1;

        if (s[n - 1] == '|')
            next[n - 1] = n - 1;
        else
            next[n - 1] = n;

        if (s[0] == '*')
            count[0] = 1;
        else
            count[0] = 0;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == '*')
            {
                count[i] = count[i - 1] + 1;
                prev[i] = prev[i - 1];
            }
            else
            {
                count[i] = count[i - 1];
                prev[i] = i;
            }

            if (s[n - 1 - i] == '|')
                next[n - 1 - i] = n - 1 - i;
            else
                next[n - 1 - i] = next[n - i];
        }

        int m = queries.size();
        vector<int> res(m, 0);

        for (int i = 0; i < m; i++)
        {
            int fIdx = next[queries[i][0]], sIdx = prev[queries[i][1]];

            if (fIdx >= sIdx)
                continue;

            res[i] = count[sIdx] - count[fIdx];
        }

        return res;
    }
};