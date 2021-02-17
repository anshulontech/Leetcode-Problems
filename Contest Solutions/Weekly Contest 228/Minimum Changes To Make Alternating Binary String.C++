// Solution:-

class Solution
{
public:
    int minOperations(string s)
    {
        int first = 0, second = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                if (s[i] == '0')
                {
                }
                else
                {
                    first++;
                }
            else if (s[i] == '0')
            {
                first++;
            }
            else
            {
            }

            if (i % 2 == 0)
                if (s[i] == '0')
                {
                    second++;
                }
                else
                {
                }
            else if (s[i] == '0')
            {
            }
            else
            {
                second++;
            }
        }

        return min(first, second);
    }
};