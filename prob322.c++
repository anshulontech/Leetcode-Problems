// https://leetcode.com/problems/coin-change/

// Time Complexity:-O(N*amount).
// Space Complexity:-O(amount).
    
// Approach:-
//     In this what we are doing is that we will us top - bottom approach in which we will check for each amount which 
// is less than given amount. And store their result in an array and for the further amount we dont need to look backward 
// but will just get their values from that vector.

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