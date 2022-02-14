// Link To Problem:-
// https://leetcode.com/problems/minimum-cost-to-set-cooking-time/

// Solution:-

class Solution
{
public:
    int minCostSetTime(int s, int m, int p, int t)
    {
        int minu = 0;

        while (t >= 100)
        {
            minu++;
            t -= 60;
        }

        int sec = t;

        int res = helper(s, m, p, minu, sec);

        if (sec < 60)
            return res;

        minu++;
        sec -= 60;

        if (minu < 100)
            res = min(res, helper(s, m, p, minu, sec));

        // cout<<endl<<endl;

        return res;
    }

    int helper(int s, int m, int p, int min, int sec)
    {
        string temp;

        if (min)
            temp += to_string(min);

        if (sec < 10 && min > 0)
            temp += '0' + to_string(sec);
        else
            temp += to_string(sec);

        int res = 0;
        // cout<<temp<<" ";

        for (auto x : temp)
        {
            if ((x - '0') != s)
            {
                s = x - '0';
                res += m;
            }

            res += p;
        }
        // cout<<res<<endl;
        return res;
    }
};