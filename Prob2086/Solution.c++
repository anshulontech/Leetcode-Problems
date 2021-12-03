// Link To Problem:-
// https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/

// Solution:-

class Solution
{
public:
    int minimumBuckets(string s)
    {
        int res = 0, n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] != 'H')
                continue;

            if (i != 0 && s[i - 1] == 'w')
                continue;

            if (i != n - 1 && s[i + 1] == '.')
            {
                s[i + 1] = 'w';
                res++;
                i++;
                continue;
            }

            if (i != 0 && s[i - 1] == '.')
            {
                s[i - 1] = 'w';
                res++;
                continue;
            }

            return -1;
        }

        return res;
    }
};