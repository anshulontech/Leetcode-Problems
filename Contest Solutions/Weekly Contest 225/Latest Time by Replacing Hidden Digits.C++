// Solution:-

class Solution
{
public:
    string maximumTime(string time)
    {
        for (int i = 0; i < 5; i++)
        {
            if (i == 2 || time[i] != '?')
                continue;

            if (i == 0)
            {
                if (time[i + 1] == '?' || (time[i + 1] >= '0' && time[i + 1] <= '3'))
                    time[i] = '2';
                else
                    time[i] = '1';
            }
            else if (i == 1)
            {
                if (time[i - 1] == '2')
                    time[i] = '3';
                else
                    time[i] = '9';
            }
            else if (i == 3)
            {
                time[i] = '5';
            }
            else
                time[i] = '9';
        }

        return time;
    }
};