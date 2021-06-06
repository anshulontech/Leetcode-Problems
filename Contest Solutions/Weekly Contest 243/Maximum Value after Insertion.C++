// Solution:-

class Solution
{
public:
    string maxValue(string s, int x)
    {
        if (s[0] == '-')
        {
            int i = 1, n = s.size();

            for (; i < n; i++)
                if (s[i] > (x + '0'))
                    break;

            return '-' + s.substr(1, i - 1) + to_string(x) + s.substr(i, n - i);
        }
        else
        {
            int i = 0, n = s.size();
            for (; i < n; i++)
                if (s[i] < (x + '0'))
                    break;

            return s.substr(0, i) + to_string(x) + s.substr(i, n - i);
        }
    }
};
