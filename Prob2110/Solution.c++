// Link To Probelm:-
// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/

// Solution:-

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        int i = 0, j = 0, n = prices.size();

        long long res = 0;

        while (i < n - 1)
        {
            j = i;
            while (i < n - 1 && prices[i] - prices[i + 1] == 1)
                i++;

            i++;

            long long count = i - j;

            res += count * (count + 1) / 2;
        }

        if (i == n - 1)
            return res + 1;
        else
            return res;
    }
};