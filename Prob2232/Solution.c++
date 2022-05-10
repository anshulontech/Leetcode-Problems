// Link To The Problem:-
// https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/

// Solution:-

class Solution
{
public:
    string minimizeResult(string s)
    {
        string res = "";
        int minValue = INT_MAX;

        int idx = 0, n = s.size();
        while (s[idx] != '+')
            idx++;

        int first = idx, second = n - idx - 1;
        int val1, val2, val3, val4;

        for (int i = 0; i < first; i++)
        {
            string f1 = s.substr(0, i);
            if (f1.size() == 0)
                val1 = 1;
            else
                val1 = stoi(f1);

            string f2 = s.substr(i, idx - i);
            int val2 = stoi(f2);

            for (int j = 1; j <= second; j++)
            {
                string s1 = s.substr(idx + 1, j);
                int val3 = stoi(s1);
                string s2 = s.substr(idx + 1 + j, second - j);
                if (s2.size() == 0)
                    val4 = 1;
                else
                    val4 = stoi(s2);

                if (val1 * (val2 + val3) * val4 < minValue)
                {
                    minValue = val1 * (val2 + val3) * val4;
                    res = f1 + "(" + f2 + "+" + s1 + ")" + s2;
                }
            }
        }

        return res;
    }
};