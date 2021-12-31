// Link To Problem:-
// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

// Solution:-

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        int n = s.size();

        if (n % 2 == 1)
            return false;

        int count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '0' || s[i] == '(')
                count1++;
            else
                count1--;

            if (locked[n - 1 - i] == '0' || s[n - 1 - i] == ')')
                count2++;
            else
                count2--;

            if (count1 < 0 || count2 < 0)
                return false;
        }

        return true;
    }
};