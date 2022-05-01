// Link To The Problem:-
// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/

// Solution:-

class Solution
{
public:
    string removeDigit(string s, char d)
    {
        int n = s.size();

        for (int i = 0; i < n - 1; i++)
            if (s[i] == d && s[i + 1] > d)
                return s.substr(0, i) + s.substr(i + 1, n - i - 1);

        for (int i = n - 1; i >= 0; i--)
            if (s[i] == d)
            {
                return s.substr(0, i) + s.substr(i + 1, n - i - 1);
            }

        return s;
    }
};