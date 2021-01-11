// Link To Problem:-
// https://leetcode.com/problems/maximum-score-from-removing-substrings/

// Solution:-

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        if (x < y)
            return removeBA(s, x, y);
        else
            return removeAB(s, x, y);
    }

private:
    int removeAB(string &s, int &x, int &y)
    {
        int res = 0;
        vector<char> store;

        for (auto c : s)
            if (c == 'b' && !store.empty() && store.back() == 'a')
            {
                store.pop_back();
                res += x;
            }
            else
                store.push_back(c);

        vector<char> store2;

        for (auto c : store)
            if (!store2.empty())
                if (c == 'a' && !store2.empty() && store2.back() == 'b')
                {
                    store2.pop_back();
                    res += y;
                }
                else
                    store2.push_back(c);
            else
                store2.push_back(c);

        return res;
    }

    int removeBA(string &s, int &x, int &y)
    {
        int res = 0;
        vector<char> store;

        for (auto c : s)
            if (c == 'a' && !store.empty() && store.back() == 'b')
            {
                store.pop_back();
                res += y;
            }
            else
                store.push_back(c);

        vector<char> store2;

        for (auto c : store)
            if (!store2.empty())
                if (c == 'b' && !store2.empty() && store2.back() == 'a')
                {
                    store2.pop_back();
                    res += x;
                }
                else
                    store2.push_back(c);
            else
                store2.push_back(c);

        return res;
    }
};