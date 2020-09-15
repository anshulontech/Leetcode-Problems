// Approach 1:-

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == ' ')
            i--;

        int end = i;

        while (i >= 0 && isalpha(s[i]))
            i--;

        return end - i;
    }
};