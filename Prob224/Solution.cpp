// Approach 1:-

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> store;

        long long int res = 0, num = 0, sign = 1;

        for (int i = 0; i < s.size(); i++)
            if (isdigit(s[i]))
                num = num * 10 + s[i] - '0';
            else if (s[i] == '+' || s[i] == '-')
            {
                res += sign * num;
                num = 0;
                sign = (s[i] == '+') ? 1 : -1;
            }
            else if (s[i] == '(')
            {
                store.push(res);
                store.push(sign);
                sign = 1;
                res = 0;
            }
            else if (s[i] == ')')
            {
                res += sign * num;
                num = 0;
                res *= store.top(), store.pop();
                res += store.top(), store.pop();
            }

        if (num != 0)
            res += sign * num;

        return res;
    }
};