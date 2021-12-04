// Link To Problem:-
// https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/

// Solution:-

class Solution
{
public:
    int minCost(vector<int> &s, vector<int> &h, vector<int> &r, vector<int> &c)
    {
        int cost = 0;

        if (s[0] < h[0])
        {
            for (int i = s[0] + 1; i <= h[0]; i++)
                cost += r[i];
        }
        else
        {
            for (int i = s[0] - 1; i >= h[0]; i--)
                cost += r[i];
        }

        if (s[1] < h[1])
        {
            for (int i = s[1] + 1; i <= h[1]; i++)
                cost += c[i];
        }
        else
        {
            for (int i = s[1] - 1; i >= h[1]; i--)
                cost += c[i];
        }

        return cost;
    }
};