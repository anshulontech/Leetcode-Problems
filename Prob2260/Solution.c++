// Link To The Problem:-
// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

// Solution:-

class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, vector<int>> map;
        int n = cards.size();

        for (int i = 0; i < n; i++)
            map[cards[i]].push_back(i);

        int res = INT_MAX;

        for (auto x : map)
        {
            int k = x.second.size();
            // cout<<x.first<<" "<<k<<endl;

            for (int i = 0; i < k - 1; i++)
                res = min(res, x.second[i + 1] - x.second[i] + 1);
        }

        if (res == INT_MAX)
            return -1;

        return res;
    }
};