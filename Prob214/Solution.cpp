// Approach 1:-

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        string rev_s = reverseIt(s);

        string temp = s + "#" + rev_s;

        vector<int> prefixArray(temp.size(), 0);

        for (int i = 1; i < prefixArray.size(); i++)
        {
            int j = prefixArray[i - 1];

            while (j > 0 && temp[i] != temp[j])
                j = prefixArray[j - 1];

            if (temp[i] == temp[j])
                prefixArray[i] = j + 1;
        }

        return rev_s.substr(0, s.size() - prefixArray[temp.size() - 1]) + s;
    }

private:
    string reverseIt(string &s)
    {
        string res;

        for (int i = s.size() - 1; i >= 0; i--)
            res += s[i];

        return res;
    }
};