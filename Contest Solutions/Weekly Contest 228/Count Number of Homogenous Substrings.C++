// Solution:-

class Solution
{
public:
    int countHomogenous(string s)
    {
        int res = 0;
        int mod = 1000000007;

        int n = s.size();

        for (int i = 0; i < n;)
        {
            int idx = i;
            while (i < n && s[i] == s[idx])
                i++;

            for (int j = 1; j <= i - idx; j++)
                res = (res + j) % mod;
        }

        return res % mod;
    }
};