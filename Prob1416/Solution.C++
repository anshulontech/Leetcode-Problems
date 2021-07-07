// Link To Problem:-
// https://leetcode.com/problems/restore-the-array/

// METHOD 1:-

class Solution
{
public:
    int numberOfArrays(string s, int k)
    {
        int n = s.size(), mod = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                dp[i] = dp[i + 1];
                continue;
            }

            long long temp = 0;

            for (int j = 1; j < 10 && i + j <= n; j++)
            {
                long long num = stoi(s.substr(i, j));
                if (num > k)
                    break;

                if (s[i + j] == '0')
                    continue;

                temp += dp[i + j];
                temp %= mod;
            }

            dp[i] = temp;
        }

        return dp[0];
    }
};