// Link To Problem:-
// https://leetcode.com/problems/valid-parentheses/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> A;

        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                A.push(s[i]);
            else
            {
                if (A.empty())
                    return 0;
                else if (s[i] == ')')
                    if (A.top() == '(')
                        A.pop();
                    else
                        return 0;
                else if (s[i] == '}')
                    if (A.top() == '{')
                        A.pop();
                    else
                        return 0;
                else if (s[i] == ']')
                    if (A.top() == '[')
                        A.pop();
                    else
                        return 0;
            }

        if (A.empty())
            return 1;
        else
            return 0;
        return 1;
    }
};