// https://leetcode.com/problems/coin-change/

// METHOD 1:-

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int Max = amount + 1;
        vector<int> store(Max, Max);
        store[0] = 0;
        for (int i = 1; i < Max; i++)
            for (int j = 0; j < coins.size(); j++)
                if (coins[j] <= i)
                    store[i] = min(store[i], store[i - coins[j]] + 1);

        return store[amount] > amount ? -1 : store[amount];
    }
};