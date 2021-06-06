// Solution:-

class Solution
{
public:
    bool isSumEqual(string fW, string sW, string tW)
    {
        int n1 = fW.size(), n2 = sW.size(), n3 = tW.size();
        int f = 0, s = 0, t = 0;

        for (int i = 0; i < n1; i++)
            f = f * 10 + (fW[i] - 'a');

        for (int i = 0; i < n2; i++)
            s = s * 10 + (sW[i] - 'a');

        for (int i = 0; i < n3; i++)
            t = t * 10 + (tW[i] - 'a');

        return (f + s) == t;
    }
};