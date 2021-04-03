// Solution:-

class Solution
{
public:
    bool squareIsWhite(string s)
    {
        int first = s[0] - 'a', second = s[1] - '1';

        if (first % 2 == 0)
        {
            if (second % 2 == 0)
                return false;
            else
                return true;
        }
        else
        {
            if (second % 2 == 0)
                return true;
            else
                return false;
        }
    }
};