// Solution:-

class Solution
{
public:
    int maxScore(string s)
    {
        int one = 0;
        int n = s.size();

        for (int i = 1; i < n; i++)
            if (s[i] == '1')
                one++;

        int res = 0, zero = 0;

        if (s[0] == '0')
        {
            zero++;
            res = one + zero;
        }
        else
        {
            res = one;
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '0')
                zero++;
            else
                one--;

            res = max(res, zero + one);
        }

        return res;
    }
};