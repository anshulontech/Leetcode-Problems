// Link To The Problem:-
// https://leetcode.com/problems/count-artifacts-that-can-be-extracted/

// Solution 1:-

class Solution
{
public:
    int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (auto x : dig)
            dp[x[0]][x[1] + 1] = 1;

        for (int i = 0; i < n; i++)
            for (int j = 1; j < n + 1; j++)
                dp[i][j] += dp[i][j - 1];

        int res = 0;

        for (auto x : artifacts)
        {
            bool isValidDig = true;

            for (int i = x[0]; i <= x[2]; i++)
                if ((dp[i][x[3] + 1] - dp[i][x[1] + 1] + ((dp[i][x[1] + 1] == dp[i][x[1]]) ? 0 : 1)) != (x[3] - x[1] + 1))
                {
                    isValidDig = false;
                    break;
                }

            if (isValidDig)
                res++;
        }

        return res;
    }
};

// Solution 2:-

class Solution
{
public:
    int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig)
    {
        set<string> set;

        for (auto x : dig)
            set.insert(to_string(x[0]) + " " + to_string(x[1]));

        int res = 0;

        for (auto x : artifacts)
        {
            bool isGood = true;
            for (int i = x[0]; i <= x[2] && isGood; i++)
                for (int j = x[1]; j <= x[3]; j++)
                {
                    string temp = to_string(i) + " " + to_string(j);

                    if (set.find(temp) == set.end())
                    {
                        isGood = false;
                        break;
                    }
                }

            if (isGood)
                res++;
        }

        return res;
    }
};