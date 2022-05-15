// Link To The Problem:-
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Solution:-

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minVal = prices[0];
        int res = 0, n = prices.size();

        for (int i = 1; i < n; i++)
        {
            res = max(res, prices[i] - minVal);
            minVal = min(minVal, prices[i]);
        }

        return res;
    }
};