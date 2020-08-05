// Approach 1 : -

class Solution
{
private:
    int max_len = 0, start, end;

public:
    string longestPalindrome(string s)
    {

        for (int i = 0; i < s.size(); i++)
        {
            revelPalindrome(s, i, i);
            revelPalindrome(s, i, i + 1);
        }

        return s.substr(start, end - start + 1);
    }

    void revelPalindrome(string &s, int i, int j)
    {
        while (i >= 0 && j < s.size() && s[i] == s[j])
            i--, j++;

        if ((j - i - 1) > max_len)
        {
            max_len = j - i - 1;
            start = i + 1;
            end = j - 1;
        }
    }
};