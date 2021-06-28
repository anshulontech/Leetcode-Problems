// Link To Problem:-
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// METHOD 1:-

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;

        int N = prices.size();

        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                if ((prices[j] - prices[i]) > max_profit)
                    max_profit = prices[j] - prices[i];

        return max_profit;
    }
};

// METHOD 2:-

class Solution
{
public:
    int maxProfit(vector<int> &price)
    {
        int min_price = INT_MAX;
        int max_profit = 0;

        int N = price.size();

        for (int i = 0; i < N; i++)
            if (price[i] < min_price)
                min_price = price[i];
            else if (price[i] - min_price > max_profit)
                max_profit = price[i] - min_price;

        return max_profit;
    }
};