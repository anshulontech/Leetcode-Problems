// Link To Problem:-
// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

// Solution:-

class Solution
{
public:
    int maxConsecutiveAnswers(string s, int k)
    {
        int res = 0;

        int i = 0, j = 0, n = s.size();
        int temp = 0;

        while (j < n)
        {
            if (s[j] == 'T')
            {
                j++;
                res = max(res, j - i);
            }
            else
            {
                if (temp < k)
                {
                    j++;
                    temp++;
                    res = max(res, j - i);
                }
                else
                {
                    while (i < j && s[i] == 'T')
                        i++;

                    i++;
                    j++;
                    res = max(res, j - i);
                }
            }
        }

        i = 0, j = 0, temp = 0;

        while (j < n)
        {
            if (s[j] == 'F')
            {
                j++;
                res = max(res, j - i);
            }
            else
            {
                if (temp < k)
                {
                    j++;
                    temp++;
                    res = max(res, j - i);
                }
                else
                {
                    while (i < j && s[i] == 'F')
                        i++;

                    i++;
                    j++;
                    res = max(res, j - i);
                }
            }
        }

        return res;
    }
};