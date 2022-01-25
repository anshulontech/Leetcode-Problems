// Link To Problem:-
// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

// Solution:-

class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        sort(cost.begin(), cost.end());

        int result = 0;

        for (int i = cost.size() - 1; i >= 0; i -= 3)
        {
            if (i == 0)
                result += cost[i];
            else
                result += cost[i] + cost[i - 1];
        }

        return result;
    }
};