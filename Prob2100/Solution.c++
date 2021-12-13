// Link To Problem:-
// https://leetcode.com/problems/find-good-days-to-rob-the-bank/

// Solution:-

class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &s, int time)
    {
        int n = s.size();

        vector<int> prev(n, 0), post(n, 0);

        for (int i = 0; i < n - 1; i++)
            if (s[i] >= s[i + 1])
                prev[i + 1] = prev[i] + 1;
            else
                prev[i + 1] = 0;

        for (int i = n - 1; i > 0; i--)
            if (s[i] >= s[i - 1])
                post[i - 1] = post[i] + 1;
            else
                post[i - 1] = 0;

        vector<int> res;

        for (int i = 0; i < n; i++)
            if (prev[i] >= time && post[i] >= time)
                res.push_back(i);

        return res;
    }
};