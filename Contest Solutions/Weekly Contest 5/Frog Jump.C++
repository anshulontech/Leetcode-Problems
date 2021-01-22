// Solution:-

class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        unordered_map<int, unordered_set<int>> store;
        int n = stones.size();
        unordered_set<int> temp;
        for (int i = 0; i < n; i++)
            store[stones[i]] = temp;

        store[0].insert(0);

        for (int i = 0; i < n; i++)
        {
            auto &temp = store[stones[i]];

            for (auto x : temp)
            {
                if (x - 1 > 0)
                {
                    store[stones[i] + x - 1].insert(x - 1);
                    if (stones[i] + x - 1 == stones[n - 1])
                        return true;
                }
                if (x > 0)
                {
                    store[stones[i] + x].insert(x);
                    if (stones[i] + x == stones[n - 1])
                        return true;
                }

                store[stones[i] + x + 1].insert(x + 1);
                if (stones[i] + x + 1 == stones[n - 1])
                    return true;
            }
        }

        return false;
    }
};