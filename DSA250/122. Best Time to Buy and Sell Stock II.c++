// Link To The Problem:-
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Solution:-

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int lastPrice = prices[0];
        int res = 0, n = prices.size();

        for (int i = 1; i < n; i++)
        {
            if (prices[i] > lastPrice)
            {
                res += prices[i] - lastPrice;
                lastPrice = prices[i];
            }
            else
                lastPrice = prices[i];
        }

        return res;
    }
};