// Solution:-

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.size() > t.size())
            return false;

        int i = 0, j = 0;

        int sLen = s.size(), tLen = t.size();

        for (; j < tLen && i < sLen; j++)
            if (t[j] == s[i])
                i++;

        return i == sLen;
    }
};

