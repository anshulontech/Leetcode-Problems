// Solution:-

class Solution
{
public:
    int getMaximumConsecutive(vector<int> &coins)
    {
        sort(coins.begin(), coins.end());
        int res = 1;
        for (auto x : coins)
        {
            if (x > res)
                break;
            res += x;
        }

        return res;
    }
};