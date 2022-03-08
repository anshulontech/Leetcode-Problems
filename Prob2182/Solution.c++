// Link To The Problem:-
// https://leetcode.com/problems/construct-string-with-repeat-limit/

// Solution:-

class Solution
{
public:
    string repeatLimitedString(string s, int rl)
    {
        vector<int> count(26, 0);

        for (auto x : s)
            count[x - 'a']++;

        string res = "";

        for (int i = 25; i >= 0; i--)
        {
            if (count[i] == 0)
                continue;

            int idx = i - 1;
            while (idx >= 0 && count[idx] == 0)
                idx--;

            while (count[i] > 0)
            {
                for (int k = 0; k < rl && count[i] > 0; k++)
                {
                    res += (i + 'a');
                    count[i]--;
                }

                if (idx < 0)
                    return res;

                if (count[i] == 0)
                    break;

                res += ('a' + idx);
                count[idx]--;

                while (idx >= 0 && count[idx] == 0)
                    idx--;
            }
        }

        return res;
    }
};