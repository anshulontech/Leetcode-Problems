// Link To Problem:-
// https://leetcode.com/problems/decode-ways-ii/

// METHOD 1:-

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();

        long long mod = 1e9 + 7;

        vector<long long> dp(n + 1);
        dp[n] = 1;
        if (s[n - 1] == '*')
            dp[n - 1] = 9;
        else if (s[n - 1] == '0')
            dp[n - 1] = 0;
        else
            dp[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
            if (s[i] == '*')
                if (s[i + 1] == '*')
                    if (i + 2 < n && s[i + 2] == '0')
                        dp[i] = (9 * dp[i + 1]) % mod;
                    else
                        dp[i] = ((9 * dp[i + 1]) % mod + (15 * dp[i + 2]) % mod) % mod;
                else if (s[i + 1] == '0')
                    dp[i] = (2 * dp[i + 2]) % mod;
                else if (s[i + 1] <= '6')
                    dp[i] = ((9 * dp[i + 1]) % mod + (2 * dp[i + 2]) % mod) % mod;
                else
                    dp[i] = ((9 * dp[i + 1]) % mod + dp[i + 2]) % mod;
            else if (s[i] == '0')
                dp[i] = 0;
            else if (s[i + 1] == '*')
                if (s[i] == '1')
                    dp[i] = (dp[i + 1] + (9 * dp[i + 2]) % mod) % mod;
                else if (s[i] == '2')
                    dp[i] = (dp[i + 1] + (6 * dp[i + 2]) % mod) % mod;
                else
                    dp[i] = dp[i + 1];
            else if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                dp[i] = (dp[i + 1] + dp[i + 2]) % mod;
            else
                dp[i] = dp[i + 1];

        return dp[0];
    }
};

// METHOD 2:-

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();

        long long mod = 1e9 + 7;

        long long first = 0, second = 0;
        second = 1;
        if (s[n - 1] == '*')
            first = 9;
        else if (s[n - 1] == '0')
            first = 0;
        else
            first = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            long long temp;
            if (s[i] == '*')
                if (s[i + 1] == '*')
                    if (i + 2 < n && s[i + 2] == '0')
                        temp = (9 * first) % mod;
                    else
                        temp = ((9 * first) % mod + (15 * second) % mod) % mod;
                else if (s[i + 1] == '0')
                    temp = (2 * second) % mod;
                else if (s[i + 1] <= '6')
                    temp = ((9 * first) % mod + (2 * second) % mod) % mod;
                else
                    temp = ((9 * first) % mod + second) % mod;
            else if (s[i] == '0')
                temp = 0;
            else if (s[i + 1] == '*')
                if (s[i] == '1')
                    temp = (first + (9 * second) % mod) % mod;
                else if (s[i] == '2')
                    temp = (first + (6 * second) % mod) % mod;
                else
                    temp = first;
            else if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                temp = (first + second) % mod;
            else
                temp = first;

            second = first;
            first = temp;
        }

        return first;
    }
};