// Solution:-

class Solution
{
public:
    bool isPrefixString(string s, vector<string> &words)
    {
        int i = 0, j = 0, k = 0;
        int n1 = s.size(), n2 = words.size();

        while (i < n1 && j < n2)
            if (k == words[j].size())
            {
                k = 0;
                j++;
            }
            else if (s[i] == words[j][k])
            {
                i++, k++;
            }
            else
                return false;

        if (i >= n1 && k == words[j].size())
            return true;
        else
            return false;
    }
};