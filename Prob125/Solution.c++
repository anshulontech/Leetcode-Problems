// Link To Problem:-
// https://leetcode.com/problems/valid-palindrome/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int start = 0, end = s.size() - 1;
        while (start < end)
            if ((s[start] <= 'z' && s[start] >= 'a') || (s[start] <= '9' && s[start] >= '0'))
                if ((s[end] <= 'z' && s[end] >= 'a') || (s[end] <= '9' && s[end] >= '0'))
                    if (s[start] == s[end])
                    {
                        start++;
                        end--;
                    }
                    else
                        return false;
                else
                    end--;
            else
                start++;

        return true;
    }
};