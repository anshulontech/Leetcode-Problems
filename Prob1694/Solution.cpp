// Link To Problem:-
// https://leetcode.com/problems/reformat-phone-number/

// Solution:-

class Solution
{
public:
    string reformatNumber(string s)
    {
        string res = "";
        int n = s.size();

        for (int i = 0; i < n; i++)
            if (s[i] != ' ' && s[i] != '-')
                res += s[i];

        n = res.size();
        s = "";

        int temp = n / 3 + ((n % 3 == 2) ? 0 : -1);

        for (int i = 0; i < temp; i++)
        {
            for (int k = 0; k < 3; k++)
                s += res[i * 3 + k];

            s += '-';
        }

        if (n % 3 == 1)
        {
            s += res[n - 4];
            s += res[n - 3];
            s += '-';
            s += res[n - 2];
            s += res[n - 1];
        }
        else if (n % 3 == 0)
        {
            s += res[n - 3];
            s += res[n - 2];
            s += res[n - 1];
        }
        else
        {
            s += res[n - 2];
            s += res[n - 1];
        }

        return s;
    }
};