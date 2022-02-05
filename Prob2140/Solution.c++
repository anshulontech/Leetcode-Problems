// Link To Problem:-
// https://leetcode.com/problems/solving-questions-with-brainpower/

// Solution:-

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();

        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            dp[i] = max(dp[i + 1], ((i + questions[i][1] + 1) < (n + 1)) ? (dp[i + questions[i][1] + 1] + questions[i][0]) : questions[i][0]);

        return dp[0];
    }
};