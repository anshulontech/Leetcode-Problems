// Solution:-

class Solution
{
public:
    string longestNiceSubstring(string s)
    {
        string res = "";
        int n = s.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isNice(s, i, j))
                {
                    int len1 = res.size(), len2 = j - i + 1;
                    if (len2 > len1)
                        res = s.substr(i, j - i + 1);
                }

        return res;
    }

private:
    bool isNice(string s, int i, int j)
    {
        vector<int> arrUpper(26, 0), arrLower(26, 0);
        for (int k = i; k <= j; k++)
            if (s[k] >= 'A' && s[k] <= 'Z')
                arrUpper[s[k] - 'A'] = 1;
            else
                arrLower[s[k] - 'a'] = 1;

        for (int k = 0; k < 26; k++)
            if ((arrUpper[k] + arrLower[k] != 2) && (arrUpper[k] + arrLower[k] != 0))
                return false;

        return true;
    }
};