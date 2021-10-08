// Link To Problem:-
// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

// Solution:-

class Solution
{
public:
    int minFlips(string s)
    {
        int n = s.size();
        int odd1 = 0, odd0 = 0, even1 = 0, even0 = 0;

        for (int i = 0; i < n; i++)
            if (i % 2 == 0)
                if (s[i] == '0')
                    odd0++;
                else
                    odd1++;
            else if (s[i] == '0')
                even0++;
            else
                even1++;

        int res = min(odd0 + even1, odd1 + even0);

        if (n % 2 == 0)
            return abs(res);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                odd0--;
                even0++;
            }
            else
            {
                odd1--;
                even1++;
            }

            swap(odd0, even0);
            swap(odd1, even1);

            res = min(res, min(odd0 + even1, odd1 + even0));
        }

        return abs(res);
    }
};