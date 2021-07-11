// Solution:-

class Solution
{
public:
    bool sumGame(string num)
    {
        int leftBlank = 0, rightBlank = 0, sum = 0, n = num.size();

        for (int i = 0; i < n / 2; i++)
            if (num[i] == '?')
                leftBlank++;
            else
                sum += (num[i] - '0');

        for (int i = n / 2; i < n; i++)
            if (num[i] == '?')
                rightBlank++;
            else
                sum -= (num[i] - '0');

        if ((leftBlank + rightBlank) % 2 == 1)
            return true;

        sum += leftBlank / 2 * 9 - rightBlank / 2 * 9;

        return sum != 0;
    }
};
