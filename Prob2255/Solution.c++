// Link To The Problem:-
// https://leetcode.com/problems/count-prefixes-of-a-given-string/

// Solution:-

class Solution
{
public:
    int countPrefixes(vector<string> &words, string s)
    {
        int res = 0, n = s.size();

        for (auto &x : words)
        {
            if (x.size() > n)
                continue;

            int i = 0;

            while (i < n && s[i] == x[i])
                i++;

            if (i != 0)
                res++;
        }

        return res;
    }
};