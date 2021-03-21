// Solution:-

class Solution
{
public:
    int secondHighest(string s)
    {
        int firstMax = -1, secondMax = -1;

        for (auto x : s)
            if (isdigit(x))
            {
                int val = x - '0';

                if (val > firstMax)
                {
                    secondMax = firstMax;
                    firstMax = val;
                }
                else if (val < firstMax && (secondMax == -1 || val > secondMax))
                    secondMax = val;
            }

        return secondMax;
    }
};