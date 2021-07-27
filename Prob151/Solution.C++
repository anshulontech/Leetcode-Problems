// Link To Problem:-
// https://leetcode.com/problems/reverse-words-in-a-string/

// METHOD 1:-

class Solution
{
public:
    string reverseWords(string s)
    {
        int start = 0, end = 0;
        while (end < s.size() && s[end] == ' ')
            end++;

        if (end)
        {
            s.erase(0, end);
        }
        reverse(s.begin(), s.end());

        start = 0, end = 0;

        while (end < s.size() && s[end] == ' ')
            end++;

        if (end)
        {
            s.erase(0, end);
        }

        start = 0, end = 0;

        while (end < s.size())
        {
            while (end < s.size() && s[end] != ' ')
                end++;

            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
            end = start;
        }

        start = 0;
        while (start < s.size() && s[start] != ' ')
            start++;

        end = start;

        while (end < s.size())
        {
            while (end < s.size() && s[end] == ' ')
                end++;

            s.erase(start, end - start - 1);

            end = start + 1;

            while (end < s.size() && s[end] != ' ')
                end++;

            start = end;
        }

        return s;
    }
};