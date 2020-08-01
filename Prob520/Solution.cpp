// Approach 1:-

class Solution
{
public:
    bool detectCapitalUse(string s)
    {
        if (s.size() < 2)
            return true;

        bool isCapital = false;

        if (s[1] <= 'Z' && s[1] >= 'A')
        {
            isCapital = true;
            if (s[0] > 'Z' || s[0] < 'A')
                return false;
        }

        for (int i = 2; i < s.size(); i++)
            if ((s[i] <= 'Z' && s[i] >= 'A') != isCapital)
                return false;

        return true;
    }
};