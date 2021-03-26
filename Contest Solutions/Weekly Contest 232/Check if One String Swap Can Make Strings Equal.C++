// Solution:-

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int idx1 = -1, idx2 = -1, count = 0;
        int n = s1.size();

        for (int i = 0; i < n; i++)
            if (s1[i] != s2[i])
                if (idx1 == -1)
                {
                    idx1 = i;
                    count++;
                }
                else
                {
                    idx2 = i;
                    count++;
                }

        if (count > 2 || count == 1)
            return false;
        if (count == 0)
            return true;

        if (s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1])
            return true;

        return false;
    }
};