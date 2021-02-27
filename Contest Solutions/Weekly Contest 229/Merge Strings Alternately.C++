// Solution:-

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int l1 = word1.size(), l2 = word2.size();

        int i = 0;
        int size = max(l1, l2);
        string res = "";

        while (i < size)
        {
            if (i < l1)
                res += word1[i];
            if (i < l2)
                res += word2[i];

            i++;
        }

        return res;
    }
};