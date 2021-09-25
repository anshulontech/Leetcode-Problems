// Link To Problem:-
// https://leetcode.com/problems/break-a-palindrome/

// Solution:-

class Solution
{
public:
    string breakPalindrome(string s)
    {
        int n = s.size();

        if (n == 1)
            return "";

        bool isAlla = true;

        for (int i = 0; i < n; i++)
        {
            if (s[i] != 'a')
            {
                if (n % 2 == 1 && ((i * 2 + 1) == n))
                    continue;
                isAlla = false;
                s[i] = 'a';
                break;
            }
        }

        if (isAlla)
        {
            s[n - 1] = 'b';
        }

        return s;
    }
};