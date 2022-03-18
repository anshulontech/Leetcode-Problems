// Link To The Problem:-
// https://leetcode.com/problems/counting-words-with-a-given-prefix/

// Solution:-

class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int res = 0, n = pref.size();

        for (auto x : words)
        {
            bool isPrefSame = true;

            if (x.size() < n)
                continue;

            for (int i = 0; i < n; i++)
                if (pref[i] != x[i])
                {
                    isPrefSame = false;
                    break;
                }

            if (isPrefSame)
                res++;
        }

        return res;
    }
};