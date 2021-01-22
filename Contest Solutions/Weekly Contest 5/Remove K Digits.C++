// Solution:-

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> store;
        int n = num.size();

        for (int i = 0; i < n; i++)
        {
            while (!store.empty() && k > 0 && store.top() > num[i])
            {
                store.pop();
                k--;
            }

            store.push(num[i]);
        }

        while (k && !store.empty())
        {
            store.pop();
            k--;
        }

        string res = "";

        while (!store.empty())
        {
            res += store.top();
            store.pop();
        }

        while (res.size() > 0 && res[res.size() - 1] == '0')
            res.erase(res.size() - 1, 1);

        reverse(res.begin(), res.end());

        if (res.size() == 0)
            return "0";
        else
            return res;
    }
};