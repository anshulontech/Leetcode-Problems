// Approach 1:-

class Solution
{
public:
    int countSegments(string s)
    {
        int res = 0;

        int i = 0;

        while (i < s.size())
        {
            int prev = i;
            while (i < s.size() && s[i] != ' ')
                i++;
            if (prev != i)
                res++;

            while (i < s.size() && s[i] == ' ')
                i++;
        }

        return res;
    }
};