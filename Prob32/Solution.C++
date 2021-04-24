// Link To Problem :-
// https://leetcode.com/problems/longest-valid-parentheses/

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size(), longest = 0;

        stack<int> store;

        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(')
                store.push(i);
            else if (!store.empty())
                if (s[store.top()] == '(')
                    store.pop();
                else
                    store.push(i);
            else
                store.push(i);

        if (store.empty())
            return n;
        else
        {
            int a = n, b = 0;
            while (!store.empty())
            {
                b = store.top();
                store.pop();
                longest = max(longest, a - b - 1);
                a = b;
            }

            longest = max(longest, a);
        }

        return longest;
    }
};